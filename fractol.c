/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:44:38 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/14 16:36:09 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_data *data, int x, int y)
{
	data->fractal_func = &julia;
	data->k = init_complex(
			4 * ((double)x / WINDOW_WIDTH - 0.5),
			4 * ((double)(WINDOW_HEIGHT - y) / WINDOW_HEIGHT - 0.5));
	data->fractal_name = ft_strdup("Julia");
}

void	init_fractal(t_data *data,
		int (*fractal_func)(struct s_data *), char *name)
{
	data->fractal_func = fractal_func;
	data->fractal_name = name;
}

t_img	*init_image(void *mlx)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		exit_error(ERROR_MALLOC);
	img->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img,
			&(img->bits_per_pixel),
			&(img->line_length),
			&(img->endian)
			);
	return (img);
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, data->fractal_name);
	data->img_curr = init_image(data->mlx);
	data->img_prev = init_image(data->mlx);
	mlx_hook(data->win, ON_DESTROY, 0, close_window, data);
	mlx_hook(data->win, ON_KEYDOWN, 0, key_pressed, data);
	mlx_hook(data->win, ON_MOUSEDOWN, 0, mouse_pressed, data);
	mlx_hook(data->win, ON_MOUSEMOVE, 0, mouse_move, data);
	data->color = 1;
	data->min.re = -2.0;
	data->min.im = -2;
	data->max.re = 2;
	data->max.im = data->min.im + (data->max.re - data->min.re) * \
		WINDOW_HEIGHT / WINDOW_WIDTH;
	data->max_iteration = MAX_ITERATION;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc >= 2)
	{
		parse(argc, argv, &data);
		init(&data);
		loop(&data);
	}
	else
	{
		usage();
		exit(1);
	}
}
