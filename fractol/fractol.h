/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:32:56 by smischni          #+#    #+#             */
/*   Updated: 2022/05/19 15:00:19 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "../mlx/mlx.h" //tbd. ob installieren oder mit pushen
# include <math.h>

typedef struct s_point {
	int		x;
	int		y;
	double	r;
	double	i;
	int		n;
}				t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	int		x_zero;
	int		y_zero;
	void	(*f_col)(t_data *img, int x, int y, t_point z);
}				t_vars;

void	display_options(void);
int		check_valid_arg_2(char *arg);

int		mandelbrot(char *color);
void	ft_mlx_pixel_put(t_data *img, int x, int y, int color);
void	img_mandelbrot(t_data *img, t_vars *vars);
int		init_mandelbrot(t_vars *vars, char *color);
void	get_r_and_i(t_point *p, t_vars *vars);
double	check_z(t_point z);
t_point	pixel_mandelbrot(t_point *p, t_vars *vars);
void	determine_colour(t_data *img, int x, int y, int c);
int		create_trgb(unsigned int t, unsigned int r, unsigned int g, unsigned int b);

void	julia(char *color);


void	determine_color(t_vars *vars, char* color);
void	color_bernstein(t_data *img, int x, int y, t_point z);
void	color_golden_hour(t_data *img, int x, int y, t_point z);
void	color_blue_hour(t_data *img, int x, int y, t_point z);
void	color_black_white(t_data *img, int x, int y, t_point z);

#endif
