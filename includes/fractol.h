// fractol.h

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MLX42.h"
#include "../libft/libft.h"

#define WIDTH 800
#define HEIGHT 800

#define BLACK		0x000000  // RGB(0, 0, 0)
#define WHITE		0xFFFFFF  // RGB(255, 255, 255)
#define RED			0xFF0000  // RGB(255, 0, 0)
#define GREEN		0x00FF00  // RGB(0, 255, 0)
#define BLUE		0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST		0xFF00FF  // A vibrant magenta
#define LIME_SHOCK			0xCCFF00  // A blinding lime
#define NEON_ORANGE			0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE	0x660066  // A deep purple
#define AQUA_DREAM			0x33CCCC  // A bright turquoise
#define HOT_PINK			0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE		0x0066FF  // A radiant blue
#define LAVA_RED			0xFF3300  // A bright, molten red

typedef enum e_fractal_sets {
	mandelbrot,
	julia,
	burning_ship,
}		t_fractal_sets;

typedef struct s_complex {
	double re;
	double im;
} t_complex;

typedef struct s_coordinates {
	int	x;
	int	y;
} t_coordinates;

typedef struct s_params {
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	double			zoom;
	double			offset_x;
	double			offset_y;
	int				max_iter;
	int				iter;
	double			escape_value;
	t_complex		*z;
	t_complex		*c;
	t_complex		*julia;
	t_fractal_sets	set;
	t_coordinates	coordinates;
} t_params;

//***PARSER***
int parser(int argc, char **argv, t_params *fractol);

//***ERROR***
void	ft_errormsg(t_params *fractol);
void	malloc_error(void);
void	ft_freefract(t_params *fractol, int flag);

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
void	my_pixel_put(int x, int y, int color, t_params *fractal);
void	handle_pixel(int x, int y, t_params *fractal);

#endif
