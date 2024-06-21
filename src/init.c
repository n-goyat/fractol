//init.c
#include "../includes/fractol.h"

void init_mandelbrot(t_params *fractal)
{
	fractal->coordinates.x = 0;
	fractal->coordinates.y = 0;
	fractal->x_max = 2.0;
	fractal->y_max = 2.0;
	fractal->x_min = -2.0;
	fractal->y_min = -2.0;
}

void init_julia(t_params *fractal, int argc, char **argv)
{
	fractal->coordinates.x = 0;
	fractal->coordinates.y = 0;
	fractal->x_max = 2.0;
	fractal->y_max = 2.0;
	fractal->x_min = -2.0;
	fractal->y_min = -2.0;
	fractal->julia->re = -0.8;  // Default real part of c for Julia set
	fractal->julia->im = 0.156; // Default imaginary part c for Julia set
	if (argc == 3)
		ft_freefract(fractal, 1);
	if (argc == 4)
	{
		fractal->julia->re = atod(argv[2]); // Real part of c for Julia set
		fractal->julia->im = atod(argv[3]); // Imaginary part of c for Julia set
		if (fractal->julia->re < -2 || fractal->julia->re > 2 || fractal->julia->im < -2 || fractal->julia->im > 2)
			ft_freefract(fractal, 1);
	}
}

int fractal_init(t_params *fractal, int argc, char **argv)
{
	fractal->c = (t_complex *)malloc(sizeof(t_complex));
	fractal->z = (t_complex *)malloc(sizeof(t_complex));
	fractal->julia = (t_complex *)malloc(sizeof(t_complex));
	if (!fractal->c || !fractal->z || !fractal->julia)
		ft_freefract(fractal, 1);
	if (fractal->set == mandelbrot)
		init_mandelbrot(fractal);
	else if (fractal->set == julia)
		init_julia(fractal, argc, argv);
	fractal->max_iter = 200;
	fractal->iter = 0;
	fractal->zoom = 0.1;
	fractal->escape_value = 4.0;
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "FRACTOL", false);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->mlx && fractal->img)
		return (1);
	ft_freefract(fractal, 1);//TODO
	return (0);
}

/*void events_init(t_params *fractal)
{
	mlx_hook(fractal->win, 2, 1L<<0, key_hook, fractal);
	mlx_hook(fractal->win, 4, 1L<<2, mouse_hook, fractal);
	mlx_hook(fractal->win, 6, 1L<<6, mouse_move_hook, fractal);
}*/