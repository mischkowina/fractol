/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:18:30 by smischni          #+#    #+#             */
/*   Updated: 2022/06/04 17:17:42 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Puts a pixel onto an image instead of putting it directly to the display.
 * Since in t_data img the pixels are stored in a one dimensional array, we
 * need to find the right pixel in the array. We skip all lines before the
 * relevant by adding (y * line_length) and then move to the relevant pixel by 
 * adding (x * (bpp / 8)). bpp = bytes per pixel.
 * @param img [t_data *] Pointer to the struct containing all image variables.
 * @param x [int] X-coordinate of the regarded pixel.
 * @param y [int] Y-coordinate of the regarded pixel.
 * @param color [int] Integer representing the color the pixel should display.
 */
void	ft_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

/**
 * Determines the coordinates on the complex plane for a single pixel, taking
 * into consideration the distance to the origin as well as the scale of the
 * coordinate system. r represents the real-number part on the x-axis, i 
 * represents the complex-number part on the y-axis.
 * @param p [t_point *] Pointer to variables describing a pixel on the display.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
 */
void	get_r_and_i(t_point *p, t_vars *vars)
{
	p->r = ((p->x - vars->x_zero) * ((vars->x_max - vars->x_min) / WIDTH));
	p->i = ((vars->y_zero - p->y) * ((vars->y_max - vars->y_min) / HEIGHT));
}

/**
 * Determines the value represented by z^2 (consisting of the real part z.r and
 * the complex part r.i). Enables to check whether the point lies within or 
 * outside the mandelbrot-set, since it lies outside when z >= 2 (or z^2 >= 4,
 * respectively).
 * @param z [t_point] Struct describing a value 'z' in the mandelbrot-formula.
 * @return [double] Returns the value of z^2
 */
double	check_z(t_point z)
{
	double	res;

	res = (z.r * z.r + z.i * z.i);
	return (res);
}

/**
 * Converts values between 0 and 255 for the dimensions transparency, red,
 * green and blue into one integer representing the color according to 
 * RGB-standard. The values are stored in the integer using bitshifting.
 * @param t [unsigned int] Value for the dimension transparency.
 * @param r [unsigned int] Value for the dimension red.
 * @param g [unsigned int] Value for the dimension green.
 * @param b [unsigned int] Value for the dimension blue.
 * @return [int] Integer representing a color according to RGB-standard.
 */
int	create_trgb(unsigned int t, unsigned int r, unsigned int g, unsigned int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/**
 * Checks whether the arguments in the argument array are valid.
 * @param argv [char **] String array containing the command line arguments.
 * @return [int] Returns 0 if both arguments are valid, else returns 1.
*/
int	check_valid_arg(char **argv)
{
	if (!argv)
		return (1);
	if (ft_strncmp(argv[1], "mandelbrot", 11) != 0)
	{
		if (ft_strncmp(argv[1], "julia_1", 8) != 0)
		{
			if (ft_strncmp(argv[1], "julia_2", 8) != 0)
			{
				if (ft_strncmp(argv[1], "julia_3", 8) != 0)
				{
					if (ft_strncmp(argv[1], "burning_ship", 13) != 0)
						return (1);
				}
			}
		}
	}
	if (ft_strncmp(argv[2], "bernstein", 11) != 0)
	{
		if (ft_strncmp(argv[2], "blue_hour", 11) != 0)
		{
			if (ft_strncmp(argv[2], "golden_hour", 13) != 0)
			{
				if (ft_strncmp(argv[2], "black/white", 13) != 0)
					return (1);
			}
		}
	}
	return (0);
}
