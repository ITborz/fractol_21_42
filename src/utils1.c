/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:45:32 by bkristen          #+#    #+#             */
/*   Updated: 2022/06/05 14:45:34 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->adr = mlx_get_data_addr(data->img, &data->pixel_bits,
			&data->line_len, &data->endian);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	key_moves(int keycode, t_data *data)
{
	if (keycode == ARROW_UP)
	{
		data->min.im += data->scale / 3 * 0.05;
		data->max.im += data->scale / 3 * 0.05;
	}
	else if (keycode == ARROW_DOWN)
	{
		data->min.im -= data->scale / 3 * 0.05;
		data->max.im -= data->scale / 3 * 0.05;
	}
	else if (keycode == ARROW_LEFT)
	{
		data->min.re -= data->scale / 3 * 0.05;
		data->max.re -= data->scale / 3 * 0.05;
	}
	else if (keycode == ARROW_RIGHT)
	{
		data->min.re += data->scale / 3 * 0.05;
		data->max.re += data->scale / 3 * 0.05;
	}
	return (0);
}

void	ft_error(void)
{
	write(2, "Wrong arguments\n", 17);
	exit(1);
}
