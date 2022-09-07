/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:30:40 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/11 19:08:38 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void move_down(t_data *data) {
	double delta;

	delta = fabs(data->max.im - data->min.im);
	data->min.im -= delta * 0.1;
	data->max.im -= delta * 0.1;
	draw_fractal(data);
}

void move_up(t_data *data) {
	double delta;

	delta = fabs(data->max.im - data->min.im);
	data->min.im += delta * 0.1;
	data->max.im += delta * 0.1;
	draw_fractal(data);
}

void move_left(t_data *data) {
	double delta;

	delta = fabs(data->max.re - data->min.re);
	data->min.re -= delta * 0.1;
	data->max.re -= delta * 0.1;
	draw_fractal(data);
}

void move_right(t_data *data) {
	double delta;

	delta = fabs(data->max.re - data->min.re);
	data->min.re += delta * 0.1;
	data->max.re += delta * 0.1;
	draw_fractal(data);
}
