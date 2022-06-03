/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:32:56 by smischni          #+#    #+#             */
/*   Updated: 2022/06/03 17:00:04 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "../mlx/mlx.h"
# include "/usr/X11/include/X11/X.h"
# include <math.h>

# define WIDTH 			1440
# define HEIGHT			1080
# define KEY_ESC		65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_ONE		49
# define KEY_TWO		50
# define KEY_THREE		51
# define KEY_FOUR		52

typedef struct s_point {
	int		x;
	int		y;
	double	r;
	double	i;
	int		n;
	double	res;
}				t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	int		(*f_init)(struct s_vars *vars, char *color);
	t_point	(*f_render)(t_point *p, struct s_vars *vars);
	void	(*f_col)(t_data *img, int x, int y, t_point z);
	void	*mlx_ptr;
	void	*win_ptr;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	int		x_zero;
	int		y_zero;
	t_data	img;
}				t_vars;

int		fractal(t_vars *vars, char *color);
int		render(t_vars *vars);
void	display_options(void);
int		check_valid_arg(char **argv);

int		init_mandelbrot(t_vars *vars, char *color);
t_point	render_mandelbrot(t_point *p, t_vars *vars);
int		optimize_mandelbrot(t_point *p);

int		init_julia1(t_vars *vars, char *color);
t_point	render_julia1(t_point *p, t_vars *vars);

int		handle_keypress(int keysym, t_vars *vars);
void	key_up_down(int key, t_vars *vars);
void	key_right_left(int key, t_vars *vars);
int		handle_mouse(int key, int x, int y, t_vars *vars);
int		close_fractal(t_vars *vars);

void	ft_mlx_pixel_put(t_data *img, int x, int y, int color);
void	get_r_and_i(t_point *p, t_vars *vars);
double	check_z(t_point z);
int		create_trgb(unsigned int t, unsigned int r,
			unsigned int g, unsigned int b);

void	determine_color(t_vars *vars, char *color);
void	color_bernstein(t_data *img, int x, int y, t_point z);
void	color_golden_hour(t_data *img, int x, int y, t_point z);
void	color_blue_hour(t_data *img, int x, int y, t_point z);
void	color_black_white(t_data *img, int x, int y, t_point z);

#endif
