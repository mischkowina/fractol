/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:33:05 by smischni          #+#    #+#             */
/*   Updated: 2022/05/18 20:26:10 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(unsigned int t, unsigned int r, unsigned int g, unsigned int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	color_bernstein(t_data *img, int x, int y, t_point z)
{
	double	t;
	double	r;
	double	b;
	double	g;
	int		col;

	t = (double)z.n / 255;
	g = 9 * (1 - t) * (t * t * t) * 255;
	r = 15 * ((1 - t) * (1 - t)) * (t * t) * 255;
	b = 8.5 * ((1 - t) * (1 - t) * (1 - t)) * t * 255;
	col = create_trgb(0, (unsigned int)r , (unsigned int)g, (unsigned int)b);
	ft_mlx_pixel_put(img, x, y, col);
}

void	color_sin(t_data *img, int x, int y, t_point z)
{
	double	r;
	double	b;
	double	g;
	int		col;

	b = sin(0.2 * z.n + 60) * 127.5 + 127.5;
	g = sin(0.15 * z.n + 40) * 127.5 + 127.5;
	r = sin(0.1 * z.n + 20) * 127.5 + 127.5;
	col = create_trgb(0, (unsigned int)r , (unsigned int)g, (unsigned int)b);
	ft_mlx_pixel_put(img, x, y, col);
}

void	color_accident(t_data *img, int x, int y, t_point z)
{
	double	t;
	int		col;
	
	t = z.n - log(log(fabs(z.r + z.i)) / log(2));
	col = t * 16777215;
	ft_mlx_pixel_put(img, x, y, col);
}