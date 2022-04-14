/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:01:55 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/14 16:44:06 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(void *data)
{
	(void)data;
	exit(0);
	return (0);
}

int	key_pressed(int keycode, void *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_up(data);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_down(data);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_left(data);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_right(data);
	else if (keycode == KEY_C)
		change_color(data);
	return (0);
}

int	mouse_pressed(int button, int x, int y, void *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom_out(data);
	else if (button == 5)
		zoom_in(data);
	return (0);
}

int	mouse_move(int x, int y, void *data)
{
	if (((t_data *)data)->fractal_func == &julia)
		julia_motion(x, y, data);
	return (0);
}
