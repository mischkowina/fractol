/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:32:56 by smischni          #+#    #+#             */
/*   Updated: 2022/05/17 19:47:37 by smischni         ###   ########.fr       */
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
}				t_vars;

void	display_options(void);

int		mandelbrot(void);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	img_mandelbrot(t_data *img, t_vars *vars);
int		init_mandelbrot(t_vars *vars);
void	get_r_and_i(t_point *p, t_vars *vars);
double	check_z(t_point z);
int		pixel_mandelbrot(t_point *p, t_vars *vars);

void	julia(void);

#endif
