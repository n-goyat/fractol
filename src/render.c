#include "../includes/fractol.h"

void render_thread_range(t_thread_data *data, int y_start, int y_end)
{
	int x = 0;
	int y = y_start;

	while (y < y_end)
	{
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
	int i = 0;

	while (i < NUM_THREADS)
	{
		thread_data[i].fractal = fractal;
		thread_data[i].start_y = i * chunk_size;
		if (i == NUM_THREADS - 1) {
			thread_data[i].end_y = HEIGHT;
		} else {
			thread_data[i].end_y = (i + 1) * chunk_size;
		}
		pthread_create(&threads[i], NULL, render_thread, &thread_data[i]);
		i++;
	}
}

void join_threads(pthread_t *threads)
{
	int i = 0;

	while (i < NUM_THREADS)
	{
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
