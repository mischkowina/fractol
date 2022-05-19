/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:30:22 by smischni          #+#    #+#             */
/*   Updated: 2022/05/19 14:39:27 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc != 3 || check_valid_arg_2(argv[2]) != 0)
		display_options();
	else
	{
		if (ft_strncmp(argv[1], "mandelbrot", 12) == 0)
			mandelbrot(argv[2]);
		else if (ft_strncmp(argv[1], "julia", 7) == 0)
			julia(argv[2]);
		else
			display_options();
	}
	return (0);
}

void	display_options(void)
{
	
	ft_printf("\n-----------------------------------------------------------------------------------------\n");
	ft_printf("Available fractals:\n\n");
	ft_printf("* mandelbrot\n");
	ft_printf("* julia\n\n");
	ft_printf("-----------------------------------------------------------------------------------------\n");
	ft_printf("Available color schemes:\n\n");
	ft_printf("* bernstein\n");
	ft_printf("* blue_hour\n");
	ft_printf("* golden_hour\n");
	ft_printf("* black/white\n\n");
	ft_printf("-----------------------------------------------------------------------------------------\n");
	ft_printf("run \"./fractol <fractal name> <color scheme>\" to display the respective fractal\n");
	ft_printf("-----------------------------------------------------------------------------------------\n\n");
}

int	check_valid_arg_2(char *arg)
{
	if (ft_strncmp(arg, "bernstein", 11) != 0)
	{
		if (ft_strncmp(arg, "blue_hour", 11) != 0)
		{
			if (ft_strncmp(arg, "golden_hour", 13) != 0)
			{
				if (ft_strncmp(arg, "black/white", 13) != 0)
					return (1);
			}
		}
	}
	return (0);	
}