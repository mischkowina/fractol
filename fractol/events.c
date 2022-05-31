/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:22:38 by smischni          #+#    #+#             */
/*   Updated: 2022/05/31 15:49:02 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	handle_keypress(int key, t_vars *vars)
{
	if (key == KEY_ESC)
		close_fractal(vars);
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		key_right_left(key, vars);
	else if (key == KEY_UP || key == KEY_DOWN)
		key_up_down(key, vars);
	return (0);
}

void	key_up_down(int key, t_vars *vars)
{
	double	y;

	mlx_destroy_image(vars->mlx_ptr, vars->img.img);
	y = (vars->y_max - vars->y_min) * 0.05;
	if (key == KEY_UP)
	{
		vars->y_zero += (0.05 * HEIGHT);
		vars->y_max += y;
		vars->y_min += y;
	}
	else if (key == KEY_DOWN)
	{
		vars->y_zero -= (0.05 * HEIGHT);
		vars->y_max -= y;
		vars->y_min -= y;
	}
	render_mandelbrot(vars);
}

void	key_right_left(int key, t_vars *vars)
{
	double	x;

	mlx_destroy_image(vars->mlx_ptr, vars->img.img);
	x = (vars->x_max - vars->x_min) * 0.05;
	if (key == KEY_RIGHT)
	{
		vars->x_zero -= (0.05 * WIDTH);
		vars->x_max += x;
		vars->x_min += x;
	}
	else if (key == KEY_LEFT)
	{
		vars->x_zero += (0.05 * WIDTH);
		vars->x_max -= x;
		vars->x_min -= x;
	}
	render_mandelbrot(vars);
}

int	handle_mouse(int key, int x, int y, t_vars *vars)
{
	double	x_axis;
	double	y_axis;
	double	mul;
	t_point	p;

	mlx_destroy_image(vars->mlx_ptr, vars->img.img);
	p.x = x;
	p.y = y;
	mul = 1;
	get_r_and_i(&p, vars);
	if (key == 4)
		mul = 0.80;
	else if (key == 5)
		mul = 1.20;
	x_axis = (vars->x_max - vars->x_min) * mul;
	y_axis = (vars->y_max - vars->y_min) * mul;
	vars->x_min = p.r - ((double)p.x * (x_axis / WIDTH));
	vars->x_max = vars->x_min + x_axis;
	vars->x_zero = (fabs(vars->x_min) / x_axis) * WIDTH;
	vars->y_max = p.i + ((double)p.y * (y_axis / HEIGHT));
	vars->y_min = vars->y_max - y_axis;
	vars->y_zero = (fabs(vars->y_max) / y_axis) * HEIGHT;
	render_mandelbrot(vars);
	return (0);
}

int	close_fractal(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->img.img);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}