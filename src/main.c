/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:45:36 by bkristen          #+#    #+#             */
/*   Updated: 2022/06/05 16:59:34 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_check	*make_args(void)
{
	t_check	*arg;

	arg = (t_check *)malloc(sizeof(t_check));
	arg->i = 0;
	arg->sign = 1;
	arg->res = 0;
	arg->k = 0;
	return (arg);
}

float	ft_jul_atoi(char *str)
{
	t_check	*args;

	args = make_args();
	if (str[args->i] == '-' || str[args->i] == '+')
		if (str[args->i++] == '-')
			args->sign = args->sign * (-1);
	while (str[args->i] >= '0' && str[args->i] <= '9')
		args->res = args->res * 10 + str[args->i++] - '0';
	if (str[args->i] == '\0')
		return (args->res);
	if (str[args->i] == '.' && str[args->i + 1] >= '0'\
	&& str[args->i + 1] <= '9')
		args->i++;
	else
		ft_error();
	while (str[args->i] >= '0' && str[args->i] <= '9')
	{
		args->res = args->res * 10 + str[args->i++] - '0';
		args->k++;
	}
	if (str[args->i] == '\0')
		return (args->sign * args->res / pow(10, args->k));
	ft_error();
	return (-1);
}

t_complex	check_argc(char *s1, char *s2)
{
	float		res1;
	float		res2;
	t_complex	jul_argc;

	res1 = ft_jul_atoi(s1);
	res2 = ft_jul_atoi(s2);
	jul_argc = init_complex(res1, res2);
	return (jul_argc);
}

int	check_fract(int argc, char **argv)
{
	t_complex	jul_argc;

	if (!ft_strcmp("mandelbrot", argv[1]))
		make_fractal();
	else if (!ft_strcmp("julia", argv[1]))
	{
		if (argc == 4)
		{
			jul_argc = check_argc(argv[2], argv[3]);
			make_fractal_julia(jul_argc);
		}
		else if (argc == 2)
		{
			jul_argc = init_complex(-0.889, -0.235);
			make_fractal_julia(jul_argc);
		}
		else
			ft_error();
	}
	else if (!ft_strcmp("burning_ship", argv[1]))
		make_fractal_bs();
	return (-1);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || check_fract(argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		write(2, "Write mandelbrot\n", 18);
		write(2, "Write julia float1 float2\n", 27);
		write(2, "Write burning_ship\n", 20);
		return (0);
	}
	return (0);
}
