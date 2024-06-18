//fractol.c
#include "../includes/fractol.h"

int parser(int argc, char **argv, t_params *fractal)
{
	if (argc < 2 || argc > 4)
		ft_errormsg(fractal);
	else if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fractal_init(fractal);
		fractal_render(fractal);
		mlx_loop(fractal->mlx);
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal_init(fractal);
		fractal_render(fractal);
		mlx_loop(fractal->mlx);
	}
	else
		ft_errormsg(fractal);
	return (0);
}

int main(int argc, char **argv)
{
	t_params fractal;
	
	/*fractal = (t_params *)malloc(sizeof(t_params));
	if (!fractal)
		malloc_error();
	parser(argc, argv, fractal);*/
	if (parser(argc, argv, &fractal))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
	//return (0);
}