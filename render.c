#include "fractol.h"

void handle_pixel(int x, int y, t_params *fractal)
{
	t_complex z;
	t_complex c;

	z.x = 0.0;
	z.y = 0.0;

	c.x = map(x, -2, +2, WIDTH);
	c.y = map(y, +2, -2, HEIGHT);
	while ()
}

void fractal_render(t_params *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
}