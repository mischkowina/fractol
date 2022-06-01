/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:30:22 by smischni          #+#    #+#             */
/*   Updated: 2022/06/01 15:11:31 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 3 || check_valid_arg(argv) != 0)
	{
		display_options();
		return (0);
	}
	else
	{
		if (ft_strncmp(argv[1], "mandelbrot", 12) == 0)
		{
			vars.f_init = init_mandelbrot;
			vars.f_render = render_mandelbrot;
		}
		else if (ft_strncmp(argv[1], "julia", 7) == 0)
		{
			julia(argv[2]);//change
		}
	}
	fractal(&vars, argv[2]);
	return (0);
}

/**
 * Function to display the mandelbrot fractal in the specified color. Calls 
 * functions to initialize the display and initializes an image for the 
 * mandelbrot fractal to be rendered in. Loops the rendering function within
 * the mlx_loop_hook and calls different hook functions in case of events.
 * @param color [char *] String containing the color specified in command line.
 * @return [int] 1 in case of error, 0 if the function worked as expected.
 */
int	fractal(t_vars *vars, char *color)
{
	if (vars->f_init(vars, color) == 1)
		return (1);
	vars->img.img = mlx_new_image(vars->mlx_ptr, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_length, &vars->img.endian);
	mlx_hook(vars->win_ptr, DestroyNotify, NoEventMask, close_fractal, vars);
	mlx_hook(vars->win_ptr, KeyPress, KeyPressMask, handle_keypress, vars);
	mlx_mouse_hook(vars->win_ptr, handle_mouse, vars);
	mlx_loop_hook(vars->mlx_ptr, vars->f_render, vars);
	mlx_loop(vars->mlx_ptr);
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
 * Checks whether the arguments in the argument array are valid.
 * @param argv [char **] String array containing the command line arguments.
 * @return [int] Returns 0 if both arguments are valid, else returns 1.
*/
int	check_valid_arg(char **argv)
{
	if (!argv)
		return (1);
	if (ft_strncmp(argv[1], "mandelbrot", 12) != 0)
	{
		if (ft_strncmp(argv[1], "julia", 7) != 0)
			return (1);
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
