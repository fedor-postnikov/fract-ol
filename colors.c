/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:33:48 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/14 16:41:35 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_data *data)
{
	if (data->color == 1)
		data->color = 2;
	else
		data->color = 1;
	draw_fractal(data);
}

int	get_color(t_data *data, int iteration, int max_iteration)
{
	if (data->color == 1)
		return (get_color1(iteration, max_iteration));
	if (data->color == 2)
		return (get_color2(iteration, max_iteration));
	return (0);
}

int	get_color1(int iteration, int max_iteration)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / (double)max_iteration;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (0 << 24 | red << 16 | green << 8 | blue);
}

int	get_color2(int iteration, int max_iteration)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / (double)max_iteration;
	red = (int)(20 * (1 - t) * pow(t, 2) * 255);
	green = (int)(2 * pow((1 - t), 3) * pow(t, 3) * 255);
	blue = (int)(2 * pow((1 - t), 2) * t * 255);
	return (0 << 24 | red << 16 | green << 8 | blue);
}
