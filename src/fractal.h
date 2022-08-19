/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:44:51 by bkristen          #+#    #+#             */
/*   Updated: 2022/06/05 16:59:26 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H

# define FRACTAL_H

# define WIDTH		900
# define HEIGHT		900
# define MAX_ITER	240

# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78

# define ESC_KEY			53
# define SPACE_KEY		49
# define C_KEY			8
# define H_KEY			4
# define R_KEY			15
# define PLUS_KEY		24
# define MINUS_KEY		27

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct t_check{
	unsigned int	i;
	int				sign;
	long long		res;
	int				k;
}	t_check;

typedef struct s_complex{
	double	re;
	double	im;
}				t_complex;

typedef struct s_data{
	void		*img;
	char		*adr;
	void		*mlx;
	void		*win;
	int			max_iteration;
	int			pixel_bits;
	int			line_len;
	int			endian;
	int			color_shift;
	int			julia_move;
	t_complex	min;
	t_complex	max;
	double		x0;
	double		y0;
	double		x;
	double		y;
	double		tmp;
	double		tmp_re;
	double		tmp_im;
	double		scale;
	double		dx;
	double		dy;
	int			it;
	double		k_re;
	float		k_im;
	float		c_re;
	float		c_im;
}				t_data;

void		data_init(t_data *data);

int			mandelbrot_fract(t_data *img);
void		create_fractal(t_data *data);
void		make_fractal(void);

int			julia_fract(t_data *data);
void		create_fractal_julia(t_data *data);
void		make_fractal_julia(t_complex jul_args);
int			julia_motion(int x, int y, t_data *data);

int			create_burning_ship(t_data *data);
void		create_fractal_ship(t_data *data);
void		make_fractal_bs(void);

void		case_hooks(t_data *data);
void		case_hooks_julia(t_data *data);
void		case_hooks_bs(t_data *data);

int			key_moves(int keycode, t_data *data);
int			key_hook_move(int keycode, t_data *data);
int			key_hook_move_julia(int keycode, t_data *data);
int			key_hook_move_bs(int keycode, t_data *data);

int			create_trgb(int t, int r, int g, int b);
int			get_new_color(int i, t_data *data);
double		interpolate(double start, double end, double interp);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

t_complex	init_complex(double re, double im);
int			exit_fractal(t_data *data);

int			ft_strcmp(char *s1, char *s2);
t_check		*make_args(void);
float		ft_jul_atoi(char *str);
t_complex	check_argc(char *s1, char *s2);
int			check_fract(int argc, char **argv);
void		ft_error(void);
#endif