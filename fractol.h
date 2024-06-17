// fractol.h

#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MLX42.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_complex {
    double re;
    double im;
} t_complex;

typedef struct s_params {
    void *mlx;
    void *win;
    void *img;
    double zoom;
    double offset_x;
    double offset_y;
    int max_iter;
    t_complex c;
} t_params;

int parser(int argc, char **argv);

void	ft_errormsg(t_params *fractol);
void malloc_error(void);

void init(t_params *fractal);

//***math***
double map(double unscaled_num, double new_min, double new_max, double old_max);




#endif
