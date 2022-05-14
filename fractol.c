/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:30:22 by smischni          #+#    #+#             */
/*   Updated: 2022/05/14 15:43:10 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_display_options();
	else
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 12) == 0)
			ft_mandelbrot();
		else if (ft_strncmp(argv[1], "Julia",7) == 0)
			ft_julia();
		else
			ft_display_options();
	}
	return (0);
}

void	ft_display_options(void)
{
	ft_printf("\navailable fractals:\n");
	ft_printf("* Mandelbrot\n");
	ft_printf("* Julia\n\n");
	ft_printf("--> run \"./fractol <fractal name>\" to display the respective fractal\n\n");
}
