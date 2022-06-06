/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:22:38 by smischni          #+#    #+#             */
/*   Updated: 2022/06/06 14:59:13 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Handles all availabe key events and carries out the respective actions /
 * calls the repective functions. Available key events are closing via ESC,
 * moving the view with the arrows and changing the color scheme with the
 * key 1 - 4.
 * @param key [int] Defines the key that has been pressed.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
*/
int	handle_keypress(int key, t_vars *vars)
{
	if (key == KEY_ESC)
		close_fractal(vars);
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		key_right_left(key, vars);
	else if (key == KEY_UP || key == KEY_DOWN)
		key_up_down(key, vars);
	else if (key == KEY_ONE)
		vars->f_col = color_bernstein;
	else if (key == KEY_TWO)
		vars->f_col = color_blue_hour;
	else if (key == KEY_THREE)
		vars->f_col = color_golden_hour;
	else if (key == KEY_FOUR)
		vars->f_col = color_black_white;
	return (0);
}

/**
 * Handles up and down key events and carries out the respective actions to
 * move the view.
 * @param key [int] Defines the key that has been pressed.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
*/
void	key_up_down(int key, t_vars *vars)
{
	double	y;

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
}

/**
 * Handles right and left key events and carries out the respective actions to
 * move the view.
 * @param key [int] Defines the key that has been pressed.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
*/
void	key_right_left(int key, t_vars *vars)
{
	double	x;

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
}

/**
 * Handles all available mouse events except for closing the window. Bye using
 * the scroll wheel of the mouse, the view zooms in or out, focussing on the 
 * pixel pointed on by the mouse pointer.
 * @param key [int] Defines the key that has been pressed.
 * @param x [int] x-coordinate of the pixel the mouse is pointing on.
 * @param y [int] y-coordinate of the pixel the mouse is pointing on.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
 * @return [int] Returns 0 if zoom is succesful, 1 if it exceeds double limit.
*/
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
		mul = 0.98;
	else if (key == 5)
		mul = 1.02;
	x_axis = (vars->x_max - vars->x_min) * mul;
	y_axis = (vars->y_max - vars->y_min) * mul;
	if (y_axis < 0.000001 || y_axis > 1000)
		return (1);
	adjust_scale(vars, &p, mul);
	vars->x_zero = (vars->x_min * -1) * (WIDTH / x_axis);
	vars->y_zero = vars->y_max * (HEIGHT / y_axis);
	return (0);
}

/**
 * Function that closes the program and frees everything properly. Gets called
 * when either the ESC key or the red cross button of the window is pressed.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
*/
int	close_fractal(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->img.img);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
