/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:33:05 by smischni          #+#    #+#             */
/*   Updated: 2022/05/24 15:55:06 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Determines which color-scheme has been defined in the program input and 
 * saves the respective function pointer in the t_vars struct.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
 * @param color [char *] String containing the color specified in command line.
 */
void	determine_color(t_vars *vars, char *color)
{
	if (ft_strncmp(color, "bernstein", 11) == 0)
		vars->f_col = color_bernstein;
	else if (ft_strncmp(color, "blue_hour", 11) == 0)
		vars->f_col = color_blue_hour;
	else if (ft_strncmp(color, "golden_hour", 13) == 0)
		vars->f_col = color_golden_hour;
	else if (ft_strncmp(color, "black/white", 13) == 0)
		vars->f_col = color_black_white;
}

/**
 * Applies a color-scheme utilizing bernstein-polynomials for a smooth color 
 * transition. Because the three polynomials ‘flow’ into each other, the color
 * will smoothly transition to the next one when iterating over t = n / 255.
 * @param img [t_data *] Pointer to the struct containing all image variables.
 * @param x [int] X-coordinate of the regarded pixel.
 * @param y [int] Y-coordinate of the regarded pixel.
 * @param z [t_point] Struct describing the resp. z in the mandelbrot-formula.
 */
void	color_bernstein(t_data *img, int x, int y, t_point z)
{
	double	t;
	double	r;
	double	b;
	double	g;
	int		col;

	t = (double)z.n / 255;
	b = 9 * (1 - t) * (t * t * t) * 255;
	g = 15 * ((1 - t) * (1 - t)) * (t * t) * 255;
	r = 8.5 * ((1 - t) * (1 - t) * (1 - t)) * t * 255;
	col = create_trgb(0, (unsigned int)r, (unsigned int)g, (unsigned int)b);
	ft_mlx_pixel_put(img, x, y, col);
}

/**
 * Applies a color-scheme utilizing sinus for a smooth color transition.
 * The color transitions from yellow on the outside to blue closer to the
 * mandelbrot-set.
 * @param img [t_data *] Pointer to the struct containing all image variables.
 * @param x [int] X-coordinate of the regarded pixel.
 * @param y [int] Y-coordinate of the regarded pixel.
 * @param z [t_point] Struct describing the resp. z in the mandelbrot-formula.
 */
void	color_golden_hour(t_data *img, int x, int y, t_point z)
{
	double	r;
	double	b;
	double	g;
	int		col;

	b = sin(0.2 * z.n + 60) * 127.5 + 127.5;
	g = sin(0.15 * z.n + 40) * 127.5 + 127.5;
	r = sin(0.1 * z.n + 20) * 127.5 + 127.5;
	col = create_trgb(0, (unsigned int)r, (unsigned int)g, (unsigned int)b);
	ft_mlx_pixel_put(img, x, y, col);
}

/**
 * Applies a color-scheme utilizing sinus for a smooth color transition.
 * The color transitions from blue on the outside to red closer to the
 * mandelbrot-set.
 * @param img [t_data *] Pointer to the struct containing all image variables.
 * @param x [int] X-coordinate of the regarded pixel.
 * @param y [int] Y-coordinate of the regarded pixel.
 * @param z [t_point] Struct describing the resp. z in the mandelbrot-formula.
 */
void	color_blue_hour(t_data *img, int x, int y, t_point z)
{
	double	r;
	double	b;
	double	g;
	int		col;

	b = sin(0.2 * z.n + 20) * 127.5 + 127.5;
	g = sin(0.15 * z.n + 10) * 127.5 + 127.5;
	r = sin(0.1 * z.n + 5) * 127.5 + 127.5;
	col = create_trgb(0, (unsigned int)r, (unsigned int)g, (unsigned int)b);
	ft_mlx_pixel_put(img, x, y, col);
}

/**
 * Applies a color-scheme utilizing sinus for a smooth color transition.
 * The color transitions between black and white.
 * @param img [t_data *] Pointer to the struct containing all image variables.
 * @param x [int] X-coordinate of the regarded pixel.
 * @param y [int] Y-coordinate of the regarded pixel.
 * @param z [t_point] Struct describing the resp. z in the mandelbrot-formula.
 */
void	color_black_white(t_data *img, int x, int y, t_point z)
{
	double	c;
	int		col;

	c = sin(0.16 * z.n + 4) * 127.5 + 127.5;
	col = create_trgb(150, (unsigned int)c, (unsigned int)c, (unsigned int)c);
	ft_mlx_pixel_put(img, x, y, col);
}
