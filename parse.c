/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:24:37 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/12 13:27:52 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void parse(int argc, char **argv, t_data *data) {
	char *fract_name;

	fract_name = argv[1];
	if (argc == 2 && \
        ft_strncmp("Mandelbrot", fract_name, ft_strlen("Mandelbrot")) == 0)
		init_fractal(data, &mandelbrot, ft_strdup("Mandelbrot"));
	else if (argc == 4 && \
        ft_strncmp("Julia", fract_name, ft_strlen("Julia")) == 0)
		init_julia(data, ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (argc == 2 && \
        ft_strncmp("BurningShip", fract_name, ft_strlen("BurningShip")) == 0)
		init_fractal(data, &ship, ft_strdup("Burning Ship"));
	else if (argc == 2 && \
        ft_strncmp("PerpendicularBurningShip", fract_name,
				   ft_strlen("PerpendicularBurningShip")) == 0)
		init_fractal(data, &perpship, ft_strdup("Perpendicular Burning Ship"));
	else if (argc == 2 && \
        ft_strncmp("CelticPerpendicular", fract_name,
				   ft_strlen("CelticPerpendicular")) == 0)
		init_fractal(data, &celticperp, ft_strdup("Celtic Perpendicular"));
	else {
		usage();
		exit(1);
	}
}
