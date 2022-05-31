/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:38:52 by smischni          #+#    #+#             */
/*   Updated: 2022/05/31 17:13:02 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Function to display the mandelbrot fractal in the specified color.
 * Calls functions to initialize the display as well as to initialize and 
 * create the first image of the mandelbrot fractal. Destroys the window and 
 * the display and frees the mlx-pointer at the end of the program.
 * @param color [char *] String containing the color specified in command line.
 * @return [int] 1 in case of error, 0 if the function worked as expected.
 */
int	mandelbrot(char *color)//Bearbeitung text
{
	t_vars	vars;

	if (init_mandelbrot(&vars, color) == 1)
		return (1);
	vars.img.img = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bpp,
			&vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.win_ptr, DestroyNotify, NoEventMask, close_fractal, &vars);
	mlx_hook(vars.win_ptr, KeyPress, KeyPressMask, handle_keypress, &vars);
	mlx_mouse_hook(vars.win_ptr, handle_mouse, &vars);
	mlx_loop_hook(vars.mlx_ptr, render_mandelbrot, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}

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
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->win_ptr);
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
 * Initializes the image to be pushed onto the display. Then iterates through 
 * each pixel of the image and determines if it lies within the mandelbrot set
 * or outside of it. In case it lies outside, calls the respective function to
 * color the pixel.
 * @param img [t_data *] Pointer to the struct containing all image variables.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
 * @return [int] tbd
 */
int	render_mandelbrot(t_vars *vars)//Bearbeitung text
{
	t_point	p;
	t_point	z;

	ft_bzero(vars->img.addr, WIDTH * HEIGHT * sizeof(int));
	p.x = 0;
	p.y = 0;
	while (p.y <= HEIGHT)
	{
		p.x = 0;
		while (p.x <= WIDTH)
		{
			z = pixel_mandelbrot(&p, vars);
			if (z.res >= 4)
				vars->f_col(&vars->img, p.x, p.y, z);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img, 0, 0);
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
t_point	pixel_mandelbrot(t_point *p, t_vars *vars)
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
