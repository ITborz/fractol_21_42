/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:45:08 by bkristen          #+#    #+#             */
/*   Updated: 2022/06/05 14:45:10 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	create_burning_ship(t_data *data)
{
	int	n;

	n = 0;
	data->c_re = data->x;
	data->c_im = data->y;
	data->x = 0;
	data->y = 0;
	while (n < MAX_ITER && (data->x * data->x + data->y * data->y) <= 4)
	{
		data->tmp = data->x;
		data->x = (data->x * data->x) - (data->y * data->y) + data->c_re;
		data->y = -2 * fabs(data->tmp * data->y) + data->c_im;
		n++;
	}
	return (n);
}

void	create_fractal_ship(t_data *data)
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
			data->it = create_burning_ship(data);
			my_mlx_pixel_put(data, x, y, get_new_color(data->it, data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	make_fractal_bs(void)
{
	t_data	data;

	data.color_shift = 0;
	data.scale = 1.1;
	data.min.re = -2;
	data.min.im = -2;
	data.max.re = 2;
	data.max.im = data.min.im + (data.max.re - data.min.re) * HEIGHT / WIDTH;
	data_init(&data);
	create_fractal_ship(&data);
	case_hooks_bs(&data);
	mlx_loop(data.mlx);
}
