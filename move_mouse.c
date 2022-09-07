/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:49:26 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/11 19:46:13 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia_motion(int x, int y, t_data *data) {
	data->k = init_complex(
			4 * ((double) x / WINDOW_WIDTH - 0.5),
			4 * ((double) (WINDOW_HEIGHT - y) / WINDOW_HEIGHT - 0.5));
	draw_fractal(data);
}

void zoom_in(t_data *data) {
	t_complex delta;

	delta = init_complex(
			fabs(data->max.re - data->min.re),
			fabs(data->max.im - data->min.im));
	data->min.re += delta.re * 0.1;
	data->min.im += delta.im * 0.1;
	data->max.re -= delta.re * 0.1;
	data->max.im -= delta.im * 0.1;
	draw_fractal(data);
}

void zoom_out(t_data *data) {
	t_complex delta;

	delta = init_complex(
			fabs(data->max.re - data->min.re),
			fabs(data->max.im - data->min.im));
	data->min.re -= delta.re * 0.1;
	data->min.im -= delta.im * 0.1;
	data->max.re += delta.re * 0.1;
	data->max.im += delta.im * 0.1;
	draw_fractal(data);
}
