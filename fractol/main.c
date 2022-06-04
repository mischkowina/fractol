/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:30:22 by smischni          #+#    #+#             */
/*   Updated: 2022/06/04 17:19:20 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * First checks if command line arguments are valid. If not, it displays the
 * valid options within the terminal. If the input is valid, it sets the
 * function pointers in t_vars vars according to the arguments specifying the
 * fractals as well as the color scheme. Lastly, calls the function to 
 * initialize mlx and render the fractal.
 * @param argc [int] Number of command line arguments.
 * @param argv [char **] String array containing the command line arguments.
 */
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
		else if (ft_strncmp(argv[1], "julia", 5) == 0)
		{
			if (julia_options(argv[1], &vars) == 1)
			{
				display_options();
				return (0);
			}
		}
		else if (ft_strncmp(argv[1], "burning_ship", 13) == 0)
		{
			vars.f_init = init_burning_ship;
			vars.f_render = render_burning_ship;
		}
		else
		{
			display_options();
			return (0);
		}
	}
	if (fractal(&vars, argv[2]) == 1)
		write(2, "Error\n", 6);
	return (0);
}

/**
 * Function to display the fractal in the specified color. Calls functions to
 * initialize the display and initializes an image for the fractal to be 
 * rendered in. Loops the rendering function within the mlx_loop_hook and calls
 * different hook functions in case of events.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
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
	mlx_loop_hook(vars->mlx_ptr, render, vars);
	mlx_loop(vars->mlx_ptr);
	return (0);
}

/**
 * First clears the image. Then iterates through each pixel of the image and 
 * determines if it lies within the fractal set or outside of it by calling the
 * fractals rendering function. In case it lies outside, calls the respective 
 * function to color the pixel. In the end, the image is pushed to the window.
 * @param vars [t_vars *] Pointer to the struct containing important variables.
 */
int	render(t_vars *vars)
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
			z = vars->f_render(&p, vars);
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
	ft_printf("* julia_1\n");
	ft_printf("* julia_2\n");
	ft_printf("* julia_3\n");
	ft_printf("* burning_ship\n\n");
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
	ft_printf("\n\n");
}
