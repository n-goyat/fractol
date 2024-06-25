#include "../includes/fractol.h"

int parser(int argc, char **argv, t_params *fractal)
{
	if (argc < 2 || argc > 4)
		return (0);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
	{
		fractal->set = mandelbrot;
		return (1);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractal->set = julia;
		if (argc == 2)
			return (1);
		if (argc == 4)
		{
			double re = atof(argv[2]);
			double im = atof(argv[3]);
			if (re >= -2 && re <= 2 && im >= -2 && im <= 2)
				return (1);
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_params *fractal;

	fractal = malloc(sizeof(t_params));
	if (!fractal)
		return (EXIT_FAILURE);
	if (!parser(argc, argv, fractal))
		ft_errormsg(fractal);
	if (!fractal_init(fractal, argc, argv))
		return (EXIT_FAILURE);
	mlx_scroll_hook(fractal->mlx, &scrollhook, fractal);
	mlx_key_hook(fractal->mlx, &keyhook, fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx);
	free_and_null(fractal, 2);
}
