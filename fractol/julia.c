/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:40:09 by smischni          #+#    #+#             */
/*   Updated: 2022/06/03 18:34:45 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol.h"

/**
 * blabla
 */
int	init_julia1(t_vars *vars, char *color)
{
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		return (1);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIDTH, HEIGHT, "Julia 1");
	if (!vars->win_ptr)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		return (1);
	}
	determine_color(vars, color);
	vars->x_max = 1.8;
	vars->x_min = -1.8;
	vars->y_max = 1.2;
	vars->y_min = -1.2;
	vars->x_zero = 720;
	vars->y_zero = 540;
	return (0);
}

/**
 * blablka
 */
t_point	render_julia1(t_point *p, t_vars *vars)
{
	t_point	z;
	t_point	tmp;
	double	r;
	double	i;

	get_r_and_i(p, vars);
	z.n = 0;
	z.r = p->r;
	z.i = p->i;
	r = -0.76;
	i = 0.0835;
	z.res = check_z(z);
	while (z.n < 255 && z.res < 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + r;
		z.i = (2 * tmp.r * tmp.i) + i;
		z.n++;
		z.res = check_z(z);
	}
	return (z);
}
