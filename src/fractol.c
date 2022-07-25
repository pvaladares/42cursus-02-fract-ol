/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:14:11 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/25 13:55:43 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

/*
 This function closes the window and quits the program in a clean way
 whenever the ESC key is pressed
*/
int	close_window_esc_key(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == XK_Left || keycode == XK_Down)
		puts("Zoom out");
	else if (keycode == XK_Right || keycode == XK_Up)
		puts("Zoom in");
	printf("Pressed key %d %c\n", keycode, keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == Button4)
		puts("4 - Zoom in");
	else if (button == Button5)
		puts("5 - Zoom out");
	(void)vars;
	puts("Entered mouse hook");
	printf("Coordinates x = %d , y = %d\n", x, y);
	return (0);
}

/*
 This function closes the window in a safe way whenever the cross on the window (X)
 is pressed
*/
int	close_window_cross_window(t_vars *vars)
{
	(void)vars;
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

/*

*/
int	main(int argc, char **argv)
{
	t_vars	vars;

	(void)(argv);
	if (argc != 3)
	{
		printf("\e[31m## error - incorrect syntax ##\n\e[0m");
		printf(
			"\e[92m./fractol <fractal-number | fractal-name or> [<optional parameters>]\n\e[0m");
		return (EXIT_FAILURE);
	}
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		perror("Error with mlx_init()");
		exit(EXIT_FAILURE);
	}
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	if (!vars.win)
	{
		perror("Error with mlx_new_window()");
		//free(vars.mlx);
		exit(EXIT_FAILURE);
	}	
	mlx_hook(vars.win, KeyRelease, KeyReleaseMask, close_window_esc_key, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_window_cross_window, &vars);
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}

// https://en.wikipedia.org/wiki/Mandelbrot_set

