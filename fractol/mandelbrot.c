/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:38:52 by smischni          #+#    #+#             */
/*   Updated: 2022/05/17 19:47:00 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WIN_WIDTH 1440
#define WIN_HEIGHT 1080
#define X_ZERO 960
#define Y_ZERO 540

int	mandelbrot(void)
{
	t_vars	vars;
	t_data	img;

	if (init_mandelbrot(&vars) == 1)
		return (1);
	img.img = mlx_new_image(vars.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img_mandelbrot(&img, &vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img.img, 0, 0);
	mlx_loop(vars.mlx_ptr);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
	mlx_destroy_display(vars.mlx_ptr);
	free(vars.mlx_ptr);
	return (0);
}

int	init_mandelbrot(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		return (1);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Mandelbrot");
	if (!vars->win_ptr)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		return (1);
	}
	vars->x_max = 1;
	vars->x_min = -2;
	vars->y_max = 1;
	vars->y_min = -1;
	vars->x_zero = 960;
	vars->y_zero = 540;
	return (0);
}

void	img_mandelbrot(t_data *img, t_vars *vars)
{
	t_point	p;
	int		i;
	
	p.x = 0;
	p.y = 0;
	i = 0;
	while (p.y <= WIN_HEIGHT)
	{
		p.x = 0;
		while (p.x <= WIN_WIDTH)
		{
			if (pixel_mandelbrot(&p, vars) != 0)
				ft_mlx_pixel_put(img, p.x, p.y, 0x00FF00FF);
			p.x++;
		}
		p.y++;
	}
}

void	get_r_and_i(t_point *p, t_vars *vars)
{
	p->r = (0 + ((p->x - vars->x_zero) / (fabs(vars->x_max) + fabs(vars->x_min))));
	p->i = (0 + ((vars->y_zero - p->y) / (fabs(vars->y_max) + fabs(vars->y_min))));
}

int	pixel_mandelbrot(t_point *p, t_vars *vars)
{
	int		i;
	t_point	z;
	t_point tmp;

	i = 0;
	z.r = 0;
	z.i = 0;
	get_r_and_i(p, vars);
	while (i < 255 && check_z(z) < 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + p->r;
		z.i = (2 * tmp.r * tmp.i) + p->i;
		i++;
	}
	if (check_z(z) < 4)
		return (0);
	else
		return (i);
}

double	check_z(t_point z)
{
	double	res;

	res = (z.r * z.r + z.i * z.i);
	return (res);
}
