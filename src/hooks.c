//hooks.c
#include "../includes/fractol.h"

void	scrollhook(double unused, double ydelta, void *param)
{
	t_params	*fractal;

	fractal = (t_params *)param;
	(void)unused;
	if (ydelta > 0)
	{
		fractal->x_min += (fractal->x_max - fractal->x_min) * fractal->zoom;
		fractal->x_max -= (fractal->x_max - fractal->x_min) * fractal->zoom;
		fractal->y_min += (fractal->y_max - fractal->y_min) * fractal->zoom;
		fractal->y_max -= (fractal->y_max - fractal->y_min) * fractal->zoom;
	}
	else
	{
		fractal->x_min -= (fractal->x_max - fractal->x_min) * fractal->zoom;
		fractal->x_max += (fractal->x_max - fractal->x_min) * fractal->zoom;
		fractal->y_min -= (fractal->y_max - fractal->y_min) * fractal->zoom;
		fractal->y_max += (fractal->y_max - fractal->y_min) * fractal->zoom;
	}
	fractal_render(fractal);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*fractal;

	fractal = (t_params *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		fractal->max_iter++;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		if (fractal->max_iter > 1)
			fractal->max_iter--;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_delete_image(fractal->mlx, fractal->img);
		mlx_terminate(fractal->mlx);
		free_and_null(fractal, 2);
		exit(MLX_SUCCESS);
	}
	fractal_render(fractal);
}
