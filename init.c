// julia.c

#include "fractol.h"

void init(t_params *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		malloc_error();//TODO
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractol");
	if (fractal->win == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img = mlx_get_data_addr(fractal->img, 
									&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	//hooks_init
	//data_init
}
