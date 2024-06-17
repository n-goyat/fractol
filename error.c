#include "fractol.h"

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
	perror("malloc error");
	exit(EXIT_FAILURE);
}