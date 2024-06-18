//error.c
#include "../includes/fractol.h"

void	ft_errormsg(t_params *fractol)
{
	ft_putendl_fd("Error, wrong input !", 2);
	ft_putendl_fd("--------------------------------------------------", 2);
	ft_putendl_fd("Guide to usage:", 2);
	ft_putendl_fd("./fractol [option1] | [option2] ", 2);
	ft_putendl_fd("option1: ./fractol mandelbrot", 2);
	ft_putendl_fd("option2: ./fractol julia [parameter] [parameter]", 2);
	free(fractol);
	exit(EXIT_FAILURE);
}

void malloc_error(void)
{
	ft_putendl_fd("malloc error", 2);
	exit(EXIT_FAILURE);
}

void	ft_freefract(t_params *fractol, int flag)
{
	free(fractol->z);
	free(fractol->c);
	free(fractol->julia);
	if (flag == 1)
		ft_errormsg(fractol);
	free(fractol);
	if (flag == 7)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
