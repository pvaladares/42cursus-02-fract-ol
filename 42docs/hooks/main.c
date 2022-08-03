/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:58:20 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/03 13:32:57 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

/*
 Register to catch all events required
*/
static void	configure_hooks(t_app *app)
{
	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask,
		key_released, &app);
	mlx_hook(app->win_ptr, ButtonPress, ButtonPressMask,
		mouse_button_pressed, &app);
	mlx_hook(app->win_ptr, MotionNotify, PointerMotionMask,
		cursor_moved, &app);
}

/*
 Initializes the mlx, window and image instances and handles any error
*/
static void	init(t_app *app)
{
	app->mlx_ptr = mlx_init();
	if (!app->mlx_ptr)
	{
		perror("Error with mlx_init()");
		exit(EXIT_FAILURE);
	}
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!app->win_ptr)
	{
		perror("Error with mlx_new_window()");
		exit(EXIT_FAILURE);
	}
	app->img_ptr = mlx_new_image(app->mlx_ptr, WIDTH, HEIGHT);
	if (!app->img_ptr)
	{
		perror("Error with mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	app->img_addr = (int *)mlx_get_data_addr(
			app->img_ptr, &app->bits_per_pixel, &app->line_length,
			&app->endian);
}

/*
 This program implements the following features:

	- a key is pressed, it will print the key code in the terminal.

	- the mouse if moved, it will print the current position of that mouse
	in the terminal.

	- a mouse is pressed, it will print the angle at which it moved over the 
	window to the terminal.
	
*/
int	main(void)
{
	t_app	app;

	init(&app);
	configure_hooks(&app);
	mlx_loop(app.mlx_ptr);
	return (0);
}
