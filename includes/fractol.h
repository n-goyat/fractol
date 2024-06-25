// fractol.h

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "MLX42.h"
#include "../libft/libft.h"

#define WIDTH 800
#define HEIGHT 800

#define NUM_THREADS 8

#define BLACK		0x000000  // RGB(0, 0, 0)
#define WHITE		0xFFFFFF  // RGB(255, 255, 255)
#define RED			0xFF0000  // RGB(255, 0, 0)
#define GREEN		0x00FF00  // RGB(0, 255, 0)
#define BLUE		0x0000FF  // RGB(0, 0, 255)


typedef enum e_fractal_sets {
	mandelbrot,
	julia,
} t_fractal_sets;

typedef struct s_complex {
	double re;
	double im;
} t_complex;

typedef struct s_params {
	void			*mlx;
	void			*win;
	void			*img;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	double			zoom;
	double			offset_x;
	double			offset_y;
	double			mouse_x;
	double			mouse_y;
	int				max_iter;
	int				iter;
	double			escape_value;
	t_complex		*z;
	t_complex		*c;
	t_complex		*julia;
	t_fractal_sets	set;
} t_params;

typedef struct {
	t_params *fractal;
	int start_y;
	int end_y;
} t_thread_data;

//***MAIN***
int parser(int argc, char **argv, t_params *fractol);

//***HOOKS***
void		scrollhook(double unused, double ydelta, void *param);
void		keyhook(mlx_key_data_t keydata, void *param);

//***ERROR***
void	ft_errormsg(t_params *fractol);
void	malloc_error(void);
void	free_and_null(t_params *fractol, int flag);

//***INIT***
int		fractal_init(t_params *fractal, int argc, char **argv);
void	init_julia(t_params *fractal, int argc, char **argv);
void	init_mandelbrot(t_params *fractal);

//***MATH***
double	map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

//***RENDER***
void	fractal_render(t_params *fractal);
void	render_thread_range(t_thread_data *data, int y_start, int y_end);
void	*render_thread(void *arg);
void	create_threads(pthread_t *threads, t_thread_data *thread_data, t_params *fractal);
void	join_threads(pthread_t *threads);

//***PIXEL***
void	compute_initial_values(int x, int y, t_params *fractal, t_complex *z, t_complex *c);
void	iterate_and_compute_color(int *color, int *i, t_params *fractal, t_complex *z, t_complex *c);
void	put_pixel(int x, int y, int color, t_params *fractal);
uint32_t set_color(int iteration, int max_iteration);
void	handle_pixel(int x, int y, t_params *fractal);

#endif
