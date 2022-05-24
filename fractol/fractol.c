/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:30:22 by smischni          #+#    #+#             */
/*   Updated: 2022/05/24 15:50:56 by smischni         ###   ########.fr       */
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

/**
 * Function displays the different program options / arguments to the terminal
 * in case of invalid/incomplete input.
*/
void	display_options(void)
{
	int	i;

	i = 0;
	ft_printf("\n");
	ft_printf("\nAvailable fractals:\n\n");
	ft_printf("* mandelbrot\n");
	ft_printf("* julia\n\n");
	while (i++ < 92)
		ft_printf("-");
	i = 0;
	ft_printf("\nAvailable color schemes:\n\n");
	ft_printf("* bernstein\n");
	ft_printf("* blue_hour\n");
	ft_printf("* golden_hour\n");
	ft_printf("* black/white\n\n");
	while (i++ < 92)
		ft_printf("-");
	i = 0;
	ft_printf("\nrun \"./fractol <fractal name> <color scheme>\"\n");
	while (i++ < 92)
		ft_printf("-");
	i = 0;
	ft_printf("\n\n");
}

/**
 * Checks whether the second argument of the command line input is a valid
 * color-scheme.
 * @param arg [char *] String containing the second command line argument.
 * @return [int] Returns 0 if the string is a valid argument, else returns 1.
*/
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
