/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:45:14 by bkristen          #+#    #+#             */
/*   Updated: 2022/06/05 15:32:35 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	exit_fractal(t_data *data)
{
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx && data->img)
		mlx_destroy_image(data->mlx, data->img);
	exit(0);
}

double	interpolate(double start, double end, double interp)
{
	return (start + ((end - start) * interp));
}
