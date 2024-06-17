#include "fractol.h"

int parser(int argc, char **argv)
{
	t_params fractal;

	if (argc < 2)
	{
		ft_errormsg("Error, wrong input !\n");
	}
	else if (argc > 4)
	{
		ft_errormsg("Error, wrong input !\n");
	}
	else if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_errormsg("Error, wrong input !\n");
	}
	return (0);
}

int main(int argc, char **argv)
{
	parser(argc, argv);
	
	return (0);
}