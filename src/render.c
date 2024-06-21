#include "../includes/fractol.h"
#include <pthread.h>

void handle_pixel(int x, int y, t_params *fractal)
{
	t_complex z;
	t_complex c;
	int i;
	int color;

	color = BLACK;
	i = 0;
	z.re = 0.0;
	z.im = 0.0;
	c.re = map(x, fractal->x_min, fractal->x_max, WIDTH);
	c.im = map(y, fractal->y_max, fractal->y_min, HEIGHT);

	while (i < fractal->max_iter) {
		t_complex temp = {z.re * z.re - z.im * z.im + c.re, 2 * z.re * z.im + c.im};
		z = temp;
		double z_sq = (z.re * z.re) + (z.im * z.im);
		if (z_sq > fractal->escape_value) {
			color = map(i, BLACK, WHITE, fractal->max_iter);
			break;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, x, y, color);
}

void render_thread_range(t_thread_data *data, int y_start, int y_end)
{
	int x, y;

	y = y_start;
	while (y < y_end) {
		x = 0;
		while (x < WIDTH) {
			handle_pixel(x, y, data->fractal);
			x++;
		}
		y++;
	}
}

void *render_thread(void *arg)
{
	t_thread_data *data = (t_thread_data *)arg;
	render_thread_range(data, data->start_y, data->end_y);
	return NULL;
}

void create_threads(pthread_t *threads, t_thread_data *thread_data, t_params *fractal)
{
	int chunk_size = HEIGHT / NUM_THREADS;
	int i;

	i = 0;
	while (i < NUM_THREADS) {
		thread_data[i].fractal = fractal;
		thread_data[i].start_y = i * chunk_size;
		thread_data[i].end_y = (i == NUM_THREADS - 1) ? HEIGHT : (i + 1) * chunk_size;
		pthread_create(&threads[i], NULL, render_thread, &thread_data[i]);
		i++;
	}
}

void join_threads(pthread_t *threads)
{
	int i;

	i = 0;
	while (i < NUM_THREADS) {
		pthread_join(threads[i], NULL);
		i++;
	}
}

void fractal_render(t_params *fractal)
{
	pthread_t threads[NUM_THREADS];
	t_thread_data thread_data[NUM_THREADS];

	create_threads(threads, thread_data, fractal);
	join_threads(threads);

	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
