/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:38:52 by smischni          #+#    #+#             */
/*   Updated: 2022/06/03 16:56:38 by smischni         ###   ########.fr       */
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
int	init_mandelbrot(t_vars *vars, char *color)
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
	vars->x_max = 1;
	vars->x_min = -2;
	vars->y_max = 1;
	vars->y_min = -1;
	vars->x_zero = 960;
	vars->y_zero = 540;
	return (0);
}

/**
 * Applies the mandelbrot formula to a single pixel, determining its 
 * coordinates on the complex plane and respectively checking whether
 * it lies within the mandelbrot-set or outside of it and how many 
 * iterations are necessary to break out of the mandelbrot-area.
 * @param p [t_point *] Pointer to variables describing a pixel on the display.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
 * @return [t_point] Struct describing the resp. z in the mandelbrot-formula.
 */
t_point	render_mandelbrot(t_point *p, t_vars *vars)
{
	t_point	z;
	t_point	tmp;

	z.n = 0;
	z.r = 0;
	z.i = 0;
	z.res = 0;
	get_r_and_i(p, vars);
	if (optimize_mandelbrot(p) == 0)
		return (z);
	while (z.n < 255 && z.res < 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + p->r;
		z.i = (2 * tmp.r * tmp.i) + p->i;
		z.n++;
		z.res = check_z(z);
	}
	return (z);
}

/**
 * Checks whether the pixel lies within defined areas of the mandelbrot set in
 * order to optimize processing time. If a pixel lies within these areas, no
 * further calculation is necessary and the pixel doesn't get colored.
 * @param p [t_point *] Pointer to variables describing a pixel on the display.
 * @return [int] 0 in case the pixel lies in one of the areas, else 1.
 */
int	optimize_mandelbrot(t_point *p)
{
	if (p->r <= 0.2 && p->r >= -0.45 && p->i <= 0.5 && p->i >= -0.5)
		return (0);
	else if (p->r <= -0.45 && p->r >= -0.65 && p->i <= 0.3 && p->i >= -0.3)
		return (0);
	else if (p->r <= -0.85 && p->r >= -1.15 && p->i <= 0.15 && p->i >= -0.15)
		return (0);
	else
		return (1);
}
