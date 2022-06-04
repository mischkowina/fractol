/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:40:09 by smischni          #+#    #+#             */
/*   Updated: 2022/06/04 18:53:48 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
int	init_julia(t_vars *vars, char *color)
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

int	julia_options(char *arg, t_vars *vars)
{
	vars->f_init = init_julia;
	vars->f_render = render_julia;
	if (ft_strncmp(arg, "julia_1", 8) == 0)
	{
		vars->r = -0.76;
		vars->i = -0.08;
		return (0);
	}
	else if (ft_strncmp(arg, "julia_2", 8) == 0)
	{
		vars->r = -1.09;
		vars->i = 0.252;
		return (0);
	}
	else if (ft_strncmp(arg, "julia_3", 8) == 0)
	{
		vars->r = 0.1071;
		vars->i = 0.5991;
		return (0);
	}
	else
		return (1);
}

/**
 * Applies the julia formula to a single pixel, determining its coordinates on 
 * the complex plane and respectively checking whether it lies within the 
 * julia-set or outside of it and how many iterations are necessary to break 
 * out of the julia-area.
 * @param p [t_point *] Pointer to variables describing a pixel on the display.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
 */
void	render_julia(t_point *p, t_vars *vars)
{
	t_point	tmp;

	get_r_and_i(p, vars);
	vars->z.n = 0;
	vars->z.r = p->r;
	vars->z.i = p->i;
	vars->z.res = check_z(vars);
	while (vars->z.n < 255 && vars->z.res < 4)
	{
		tmp.r = vars->z.r;
		tmp.i = vars->z.i;
		vars->z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + vars->r;
		vars->z.i = (2 * tmp.r * tmp.i) + vars->i;
		vars->z.n++;
		vars->z.res = check_z(vars);
	}
}
