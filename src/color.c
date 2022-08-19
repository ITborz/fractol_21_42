/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:45:21 by bkristen          #+#    #+#             */
/*   Updated: 2022/06/05 14:45:23 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + (y * data->line_len + x * (data->pixel_bits / 8));
	*(unsigned int *)dst = color;
}

int	get_new_color(int i, t_data *data)
{
	(void)data;
	if (i >= MAX_ITER)
		return (0);
	else
		return (create_trgb(0, ((10 + data->color_shift) % 3 * 4 * i) % 256,
				((11 + data->color_shift) % 3 * 4 * i) % 256,
				((12 + data->color_shift) % 3 * 4 * i) % 256));
}
