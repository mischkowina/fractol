/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:22:38 by smischni          #+#    #+#             */
/*   Updated: 2022/05/26 15:43:10 by smischni         ###   ########.fr       */
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
