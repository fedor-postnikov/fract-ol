/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:08:05 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/12 13:22:27 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(t_data *data) {
	t_complex z;
	int iteration;

	z = init_complex(data->c.re, data->c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		   && iteration < data->max_iteration) {
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + data->c.re,
				2.0 * z.re * z.im + data->c.im);
		iteration++;
	}
	return (iteration);
}

int julia(t_data *data) {
	int iteration;
	t_complex z;

	iteration = 0;
	z = init_complex(data->c.re, data->c.im);
	while (pow(z.re, 2) + pow(z.im, 2) <= 4 \
 && (iteration < data->max_iteration)) {
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + data->k.re,
				2.0 * z.re * z.im + data->k.im);
		iteration++;
	}
	return (iteration);
}

int ship(t_data *data) {
	int iteration;
	t_complex z;

	iteration = 0;
	z = init_complex(data->c.re, data->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		   && iteration < data->max_iteration) {
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + data->c.re,
				-2.0 * fabs(z.re * z.im) + data->c.im);
		iteration++;
	}
	return (iteration);
}

int perpship(t_data *data) {
	int iteration;
	t_complex z;

	iteration = 0;
	z = init_complex(data->c.re, data->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		   && iteration < data->max_iteration) {
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + data->c.re,
				-2.0 * z.re * fabs(z.im) + data->c.im);
		iteration++;
	}
	return (iteration);
}

int celticperp(t_data *data) {
	int iteration;
	t_complex z;

	iteration = 0;
	z = init_complex(data->c.re, data->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		   && iteration < data->max_iteration) {
		z = init_complex(
				fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + data->c.re,
				-2.0 * fabs(z.re) * z.im + data->c.im);
		iteration++;
	}
	return (iteration);
}
