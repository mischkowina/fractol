/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:22:38 by smischni          #+#    #+#             */
/*   Updated: 2022/05/26 17:28:39 by smischni         ###   ########.fr       */
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
	int	x_shft;
	int	y_shft;

	x_shft = 0;
	y_shft = 0;
	if (x != (WIDTH / 2))
		x_shft = x - (WIDTH / 2);
	if (y != (HEIGHT / 2))
		y_shft = (HEIGHT / 2) - y;
	if (key == 4)
	{
		vars->x_max = vars->x_max * 0.98;
		vars->x_min = vars->x_min * 0.98;
		vars->y_max = vars->y_max * 0.98;
		vars->y_min = vars->y_min * 0.98;
	}
	else if (key == 5)
	{
		vars->x_max = vars->x_max * 1.02;
		vars->x_min = vars->x_min * 1.02;
		vars->y_max = vars->y_max * 1.02;
		vars->y_min = vars->y_min * 1.02;
	}
	return (0);
}
