/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:30:08 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/12 13:31:22 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putendl_fd("Usage: ./fractol <fractal name> [int 1] [int 2]",
		STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	ft_putendl_fd("Note: [int 1] and [int 2] parameters \
only applies for Julia fractal", STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	ft_putendl_fd("Avaialable fractals (type name to display):", STDOUT_FILENO);
	ft_putendl_fd("> Mandelbrot", STDOUT_FILENO);
	ft_putendl_fd("> Julia", STDOUT_FILENO);
	ft_putendl_fd("> BurningShip", STDOUT_FILENO);
	ft_putendl_fd("> PerpendicularBurningShip", STDOUT_FILENO);
	ft_putendl_fd("> CelticPerpendicular", STDOUT_FILENO);
}
