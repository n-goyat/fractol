//init.c
#include "../includes/fractol.h"

void data_init(t_params *fractal)
{
	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->max_iter = 100;
	fractal->escape_value = 4.0; // Adjust as needed
	fractal->c.re = 0.0;
	fractal->c.im = 0.0;
}

void fractal_init(t_params *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (fractal->mlx == NULL)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractol");
	if (fractal->win == NULL)
	{
		/*mlx_delete_image(fractol->mlx, fractol->img);
		mlx_terminate(fractol->mlx);
		free(fractal->mlx);*/
		malloc_error();
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img == NULL)
	{
		/*mlx_delete_image(fractol->mlx, fractol->img);
		mlx_terminate(fractol->mlx);
		free(fractal->mlx);*/
		malloc_error();
	}
	fractal->addr = mlx_get_data_addr(fractal->img, 
									&fractal->bpp, &fractal->line_len, &fractal->endian);
	data_init(fractal);
}

/*void events_init(t_params *fractal)
{
	mlx_hook(fractal->win, 2, 1L<<0, key_hook, fractal);
	mlx_hook(fractal->win, 4, 1L<<2, mouse_hook, fractal);
	mlx_hook(fractal->win, 6, 1L<<6, mouse_move_hook, fractal);
}*/