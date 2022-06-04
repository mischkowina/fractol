/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:02:51 by smischni          #+#    #+#             */
/*   Updated: 2022/06/04 19:09:02 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Checks whether the arguments in the argument array are valid.
 * @param argv [char **] String array containing the command line arguments.
 * @return [int] Returns 0 if both arguments are valid, else returns 1.
*/
int	check_valid_arg(char **argv)
{
	if (!argv)
		return (1);
	else if (check_arg1(argv[1]) == 1 || check_arg2(argv[2]) == 1)
		return (1);
	else
		return (0);
}

int	check_arg1(char *arg)
{
	if (ft_strncmp(arg, "mandelbrot", 11) != 0)
	{
		if (ft_strncmp(arg, "julia_1", 8) != 0)
		{
			if (ft_strncmp(arg, "julia_2", 8) != 0)
			{
				if (ft_strncmp(arg, "julia_3", 8) != 0)
				{
					if (ft_strncmp(arg, "burning_ship", 13) != 0)
						return (1);
				}
			}
		}
	}
	return (0);
}

int	check_arg2(char *arg)
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
