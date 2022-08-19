/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:45:02 by bkristen          #+#    #+#             */
/*   Updated: 2022/06/05 16:26:08 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	julia_motion(int x, int y, t_data *data)
{
	if (data->julia_move == 0)
	{
		data->k_re = 4 * ((double)x / WIDTH - 0.5);
		data->k_im = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
		create_fractal_julia(data);
	}
	return (0);
}

int	julia_fract(t_data *data)
{
	int	n;

	n = 0;
	while (n < MAX_ITER && (data->x * data->x + data->y * data->y) <= 4)
	{
		data->tmp = data->x;
		data->x = (data->x * data->x) - (data->y * data->y) + data->k_re;
		data->y = (2 * data->tmp * data->y) + data->k_im;
		n++;
	}
	return (n);
}

void	create_fractal_julia(t_data *data)
{
	int	x;
	int	y;

	data->dx = (data->max.re - data->min.re) / (WIDTH - 1);
	data->dy = (data->max.im - data->min.im) / (HEIGHT - 1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->y = data->max.im - y * data->scale * data->dy;
			data->x = data->min.re + x * data->scale * data->dx;
			data->it = julia_fract(data);
			my_mlx_pixel_put(data, x, y, get_new_color(data->it, data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	make_fractal_julia(t_complex jul_argc)
{
	t_data	data;

	data.julia_move = 1;
	data.color_shift = 0;
	data.scale = 1.1;
	data.min.re = -2;
	data.min.im = -2;
	data.max.re = 2;
	data.max.im = data.min.im + (data.max.re - data.min.re) * HEIGHT / WIDTH;
	data.k_re = jul_argc.re;
	data.k_im = jul_argc.im;
	data_init(&data);
	create_fractal_julia(&data);
	case_hooks_julia(&data);
	mlx_loop(data.mlx);
}
