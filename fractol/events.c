/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:22:38 by smischni          #+#    #+#             */
/*   Updated: 2022/05/27 12:03:45 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int key, t_vars *vars)
{
	double	x;
	double	y;

	x = ((fabs(vars->x_max) + fabs(vars->x_min)) / WIDTH) * 0.05;
	y = ((fabs(vars->x_max) + fabs(vars->x_min)) / WIDTH) * 0.05;
	if (key == KEY_ESC)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	else if (key == KEY_RIGHT)
	{
		vars->x_zero -= (0.05 * WIDTH);
		vars->x_max += x;
		vars->x_min -= x;
	}
	else if (key == KEY_LEFT)
	{
		vars->x_zero += (0.05 * WIDTH);
		vars->x_max -= x;
		vars->x_min += x;
	}
	else if (key == KEY_UP)
	{
		vars->y_zero += (0.05 * HEIGHT);
		vars->y_max += y;
		vars->y_min -= y;
	}
	else if (key == KEY_DOWN)
	{
		vars->y_zero -= (0.05 * HEIGHT);
		vars->y_max -= y;
		vars->y_min += y;
	}
	return (0);
}

int	handle_mouse(int key, int x, int y, t_vars *vars)
{
	double	x_axis;
	double	y_axis;
	double	mul;
	t_point	p;

	p.x = x;
	p.y = y;
	mul = 1;
	get_r_and_i(&p, vars);
	if (key == 4)
		mul = 0.8;
	else if (key == 5)
		mul = 1.2;
	x_axis = (fabs(vars->x_min) + fabs(vars->x_max)) * mul;
	y_axis = (fabs(vars->y_min) + fabs(vars->y_max)) * mul;
	vars->x_min = p.r - (p.x * (x_axis / WIDTH));
	vars->x_max = vars->x_min + x_axis;
	vars->x_zero = (fabs(vars->x_min) / x_axis) * WIDTH;
	vars->y_max = p.i + (p.y * (y_axis / HEIGHT));
	vars->y_min = vars->y_max - y_axis;
	vars->y_zero = (fabs(vars->y_max) / y_axis) * HEIGHT;
	return (0);
}
