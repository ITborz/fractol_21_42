/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:45:45 by bkristen          #+#    #+#             */
/*   Updated: 2022/06/05 16:33:39 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	change_color_c(t_data *data)
{
	data->color_shift = (data->color_shift + 1) % 3;
	create_fractal(data);
}

int	key_hook_move(int keycode, t_data *data)
{
	key_moves(keycode, data);
	if (keycode == ESC_KEY)
		exit_fractal(data);
	else if (keycode == C_KEY)
		change_color_c(data);
	create_fractal(data);
	return (0);
}

static int	mouse_hook(int x, int y, double zoom, t_data *data)
{
	double		interpolation;
	t_complex	mouse;

	mouse = init_complex(
			(double)x / (WIDTH / fabs(data->max.re - data->min.re)) + \
			data->min.re,
			(double)y / (HEIGHT / fabs(data->max.im - data->min.im)) * \
			-1 + data->max.im);
		interpolation = 1.0 / zoom;
		data->min.re = interpolate(mouse.re, data->min.re, interpolation);
		data->min.im = interpolate(mouse.im, data->min.im, interpolation);
		data->max.re = interpolate(mouse.re, data->max.re, interpolation);
		data->max.im = interpolate(mouse.im, data->max.im, interpolation);
	return (0);
}

static int	zoom(int mousecode, int x, int y, t_data *data)
{
	if (mousecode == MOUSE_SCROLL_UP)
		mouse_hook(x, y, 1.20, data);
	else if (mousecode == MOUSE_SCROLL_DOWN)
		mouse_hook(x, y, 0.80, data);
	mlx_clear_window(data->mlx, data->win);
	create_fractal(data);
	return (0);
}

void	case_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 0, key_hook_move, data);
	mlx_hook(data->win, 17, 0, close, data);
	mlx_hook(data->win, 4, 0, zoom, data);
}
