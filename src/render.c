//render.c
#include "../includes/fractol.h"

void my_pixel_put(int x, int y, int color)
{
	char *pixel;

	pixel = fractal->addr + (y * fractal->line_len + x * (fractal->bpp / 8));
	*(unsigned int *)pixel = color;
}

void handle_pixel(int x, int y, t_params *fractal)
{
	t_complex z;
	t_complex c;
	i = 0;
	int color;

	z.re = 0.0;
	z.im = 0.0;
	c.re = map(x, -2, +2, WIDTH);
	c.im = map(y, +2, -2, HEIGHT);
	while (i < fractal->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.re * z.re) + (z.im * z.im) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->max_iter);
			my_pixel_put(fractal, x, y, color);//TODO
			return ;
		}
		i++;
	}
	my_pixel_put(fractal, x, y, BLACK);
}

void fractal_render(t_params *fractal)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
