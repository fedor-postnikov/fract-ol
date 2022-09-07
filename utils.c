/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:26:47 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/12 13:23:38 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex init_complex(double re, double im) {
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void exit_error(int error_code) {
	exit(error_code);
}

void loop(t_data *data) {
	draw_fractal(data);
	mlx_loop(data->mlx);
}
