/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:22:38 by smischni          #+#    #+#             */
/*   Updated: 2022/05/27 22:11:04 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	handle_keypress(int key, t_vars *vars)
{
	if (key == KEY_ESC)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		key_right_left(key, vars);
	else if (key == KEY_UP || key == KEY_DOWN)
		key_up_down(key, vars);
	return (0);
}

void	key_up_down(int key, t_vars *vars)
{
	double	y;

	y = ((vars->y_max - vars->x_min) / HEIGHT) * 0.05;
	if (key == KEY_UP)
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
}

void	key_right_left(int key, t_vars *vars)
{
	double	x;

	x = ((vars->x_max - vars->x_min) / WIDTH) * 0.05;
	if (key == KEY_RIGHT)
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
		mul = 0.85;
	else if (key == 5)
		mul = 1.15;
	x_axis = (vars->x_max - vars->x_min) * mul;
	y_axis = (vars->y_max - vars->y_min) * mul;
	vars->x_min = p.r - ((double)p.x * (x_axis / WIDTH));
	vars->x_max = vars->x_min + x_axis;
	vars->x_zero = (fabs(vars->x_min) / x_axis) * WIDTH;
	vars->y_max = p.i + ((double)p.y * (y_axis / HEIGHT));
	vars->y_min = vars->y_max - y_axis;
	vars->y_zero = (fabs(vars->y_max) / y_axis) * HEIGHT;
	return (0);
}
