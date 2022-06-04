/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:04:39 by smischni          #+#    #+#             */
/*   Updated: 2022/06/04 17:56:44 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Initializes the connection between software and the display and initializes 
 * a new window. In case of failure during this process, everything is freed.
 * Else it defines important variables, like the function for the color scheme,
 * the origin of the complex plane as well as the scale of the axes.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
 * @param color [char *] String containing the color specified in command line.
 * @return [int] 1 in case of error, 0 if the function worked as expected.
 */
int	init_burning_ship(t_vars *vars, char *color)
{
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		return (1);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIDTH, HEIGHT, "Mandelbrot");
	if (!vars->win_ptr)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		return (1);
	}
	determine_color(vars, color);
	vars->x_max = 2;
	vars->x_min = -1;
	vars->y_max = 2;
	vars->y_min = -1;
	vars->x_zero = 480;
	vars->y_zero = 720;
	return (0);
}

/**
 * Applies the burning-ship formula to a single pixel, determining its 
 * coordinates on the complex plane and respectively checking whether it lies 
 * within the burning ship or outside of it and how many iterations are 
 * necessary to break out of the burning-ship-area.
 * @param p [t_point *] Pointer to variables describing a pixel on the display.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
 * @return [t_point] Struct describing the resp. z in the mandelbrot-formula.
 */
t_point	render_burning_ship(t_point *p, t_vars *vars)
{
	t_point	z;
	t_point	tmp;

	z.n = 0;
	z.r = 0;
	z.i = 0;
	z.res = 0;
	get_r_and_i(p, vars);
	while (z.n < 255 && z.res < 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) - p->r;
		z.i = 2 * fabs(tmp.r * tmp.i) - p->i;
		z.n++;
		z.res = check_z(z);
	}
	return (z);
}
