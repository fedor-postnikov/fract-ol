/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalfredi <dalfredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:44:48 by dalfredi          #+#    #+#             */
/*   Updated: 2022/04/14 16:44:41 by dalfredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"

//errors
# define ERROR_MALLOC		1

// windows properties
# define WINDOW_WIDTH		1000
# define WINDOW_HEIGHT		1000
# define WINDOW_HEADER		"fractol"

// events code from X11
# define ON_DESTROY			17
# define ON_KEYDOWN			2
# define ON_MOUSEDOWN		4
# define ON_MOUSEMOVE		6

// mac os key codes
# define KEY_ESC			53
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_C				8
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

// constants
# define MAX_ITERATION		60

typedef struct s_complex {
	double	im;
	double	re;
}	t_complex;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data {
	void		*mlx;
	void		*win;
	t_img		*img_curr;
	t_img		*img_prev;
	int			(*fractal_func)(struct s_data *);
	char		*fractal_name;
	int			max_iteration;
	int			color;
	t_complex	z;
	t_complex	c;
	t_complex	k;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
}	t_data;

// utils
t_complex	init_complex(double re, double im);
void		exit_error(int error_code);
void		loop(t_data *data);

// usage
void		usage(void);

//parse
void		parse(int argc, char **argv, t_data *data);

// init
void		init_julia(t_data *data, int x, int y);
void		init_fractal(t_data *data,
				int (*fractal_func)(struct s_data *), char *name);

// fractal functions
int			mandelbrot(t_data *data);
int			julia(t_data *data);
int			ship(t_data *data);
int			perpship(t_data *data);
int			celticperp(t_data *data);

// events
int			close_window(void *data);
int			key_pressed(int keycode, void *data);
int			mouse_pressed(int button, int x, int y, void *data);
int			mouse_move(int x, int y, void *data);
void		change_color(t_data *data);

// draw
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
void		draw_fractal(t_data *data);

//colors
int			get_color(t_data *data, int iteration, int max_iteration);
int			get_color1(int iteration, int max_iteration);
int			get_color2(int iteration, int max_iteration);

// movements
void		julia_motion(int x, int y, t_data *data);
void		zoom_in(t_data *data);
void		zoom_out(t_data *data);
void		move_down(t_data *data);
void		move_up(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

#endif
