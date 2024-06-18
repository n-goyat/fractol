//math.c
#include "../includes/fractol.h"

double map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return (new_min + (new_max - new_min) * (unscaled_num / old_max));
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex res;

	res.re = z1.re + z2.re;
	res.im = z1.im + z2.im;
	return (res);
}

t_complex square_complex(t_complex z)
{
	t_complex res;

	res.re = z.re * z.re - z.im * z.im;
	res.im = 2 * z.re * z.im;
	return (res);
}
