//error.c
#include "../includes/fractol.h"

void	ft_errormsg(t_params *fractol)
{
	ft_putendl_fd("Error: Invalid input detected!", 2);
	ft_putendl_fd("How to use Fractol:", 2);
	ft_putendl_fd("./fractol [option1] | [option2] ", 2);
	ft_putendl_fd("option1: ./fractol mandelbrot", 2);
	ft_putendl_fd("option2: ./fractol julia [parameter] [parameter]", 2);
	ft_putendl_fd("parameters have to be >= -2 && <= 2", 2);
	free(fractol);
	exit(EXIT_FAILURE);
}

void malloc_error(void)
{
	ft_putendl_fd("malloc error", 2);
	exit(EXIT_FAILURE);
}

void	free_and_null(t_params *fractol, int flag)
{
	free(fractol->z);
	free(fractol->c);
	free(fractol->julia);
	fractol->z = NULL;
	fractol->c = NULL;
	fractol->julia = NULL;
	if (flag == 1)
		ft_errormsg(fractol);
	free(fractol);
	if (flag == 2)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
