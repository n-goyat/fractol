//render.c
#include "../includes/fractol.h"

/*void my_pixel_put(int x, int y, int color, t_params *fractal)
{
	char *pixel;

	pixel = fractal->addr + (y * fractal->line_len + x * (fractal->bpp / 8));
	*(unsigned int *)pixel = color;
}*/

void handle_pixel(int x, int y, t_params *fractal)
{
	printf("Debug: x=%d, y=%d\n", x, y);
	t_complex z;
	t_complex c;
	int i;;
	int color;

	color = BLACK;
	i = 0;
	z.re = 0.0;
	z.im = 0.0;
	c.re = map(x, -2, +2, WIDTH);
	c.im = map(y, +2, -2, HEIGHT);
	printf("Debug: c.re=%.2f, c.im=%.2f\n", c.re, c.im);
	while (i < fractal->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		double z_sq = (z.re * z.re) + (z.im * z.im);
		if (z_sq > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->max_iter);
			mlx_put_pixel(fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, x, y, color);
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
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
