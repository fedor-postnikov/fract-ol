/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:30:14 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/14 16:36:44 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void swap_images(t_data *data) {
	t_img *tmp;

	tmp = data->img_curr;
	data->img_curr = data->img_prev;
	data->img_prev = tmp;
}

void my_mlx_pixel_put(t_img *data, int x, int y, int color) {
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void draw_fractal(t_data *data) {
	int x;
	int y;
	int iter;

	data->factor.re = (data->max.re - data->min.re) / (WINDOW_WIDTH - 1);
	data->factor.im = (data->max.im - data->min.im) / (WINDOW_HEIGHT - 1);
	y = 0;
	while (y < WINDOW_HEIGHT) {
		data->c.im = data->max.im - y * data->factor.im;
		x = 0;
		while (x < WINDOW_WIDTH) {
			data->c.re = data->min.re + x * data->factor.re;
			iter = data->fractal_func(data);
			my_mlx_pixel_put(data->img_prev, x, y,
							 get_color(data, iter, data->max_iteration));
			x++;
		}
		y++;
	}
	swap_images(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_curr->img, 0, 0);
}
