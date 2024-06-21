//pixel.c
#include "../includes/fractol.h"

void compute_initial_values(int x, int y, t_params *fractal, t_complex *z, t_complex *c)
{
	if (fractal->set == mandelbrot)
	{
		z->re = 0.0;
		z->im = 0.0;
		c->re = map(x, fractal->x_min, fractal->x_max, WIDTH);
		c->im = map(y, fractal->y_max, fractal->y_min, HEIGHT);
	}
	else if (fractal->set == julia)
	{
		z->re = map(x, fractal->x_min, fractal->x_max, WIDTH);
		z->im = map(y, fractal->y_max, fractal->y_min, HEIGHT);
		c->re = fractal->julia->re;
		c->im = fractal->julia->im;
	}
}

void iterate_and_compute_color(int *color, int *i, t_params *fractal, t_complex *z, t_complex *c)
{
	while (*i < fractal->max_iter) {
		t_complex temp = {z->re * z->re - z->im * z->im + c->re, 2 * z->re * z->im + c->im};
		*z = temp;
		double z_sq = (z->re * z->re) + (z->im * z->im);
		if (z_sq > fractal->escape_value) {
			*color = map(*i, BLACK, WHITE, fractal->max_iter);
			break;
		}
		(*i)++;
	}
}

void put_pixel(int x, int y, int color, t_params *fractal)
{
	mlx_put_pixel(fractal->img, x, y, color);
}

void handle_pixel(int x, int y, t_params *fractal)
{
	t_complex z;
	t_complex c;
	int i = 0;
	int color = BLACK;

	compute_initial_values(x, y, fractal, &z, &c);
	iterate_and_compute_color(&color, &i, fractal, &z, &c);
	put_pixel(x, y, color, fractal);
}
