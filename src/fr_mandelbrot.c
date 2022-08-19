/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:44:56 by bkristen          #+#    #+#             */
/*   Updated: 2022/06/05 14:44:58 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot_fract(t_data *data)
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
		data->y = (2 * data->tmp * data->y) + data->c_im;
		n++;
	}
	return (n);
}

void	create_fractal(t_data *data)
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
			data->it = mandelbrot_fract(data);
			my_mlx_pixel_put(data, x, y, get_new_color(data->it, data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	make_fractal(void)
{
	t_data	data;

	data.color_shift = 0;
	data.scale = 1.1;
	data.min.re = -2;
	data.min.im = -2;
	data.max.re = 2;
	data.max.im = data.min.im + (data.max.re - data.min.re) * HEIGHT / WIDTH;
	data_init(&data);
	create_fractal(&data);
	case_hooks(&data);
	mlx_loop(data.mlx);
}
