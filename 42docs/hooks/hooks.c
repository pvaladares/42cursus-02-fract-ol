/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:58:20 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 23:25:45 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

/*
 This routine is executed every loop
*/
int	next_frame(t_app *app)
{
	//int	x;
	//int	y;

	(void)app;
	/*
	mlx_mouse_get_pos(app->mlx_ptr, app->win_ptr, &x, &y); // segmentation fault
	if (x != app->x_cursor_saved || y != app->y_cursor_saved)
	{
		printf("New mouse position (%d), (%d)\n", x, y);
		app->x_cursor_saved = x;
		app->y_cursor_saved = y;
	}
	*/
	return (0);
}

/*
 Initializes the mlx, window and image instances and handles any error
*/
static void	init(t_app *app, t_img *img)
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
	img->img_ptr = mlx_new_image(app->mlx_ptr, WIDTH, HEIGHT);
	if (!img->img_ptr)
	{
		perror("Error with mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	img->addr = (int *)mlx_get_data_addr(
			img->img_ptr, &img->bits_per_pixel, &img->line_length,
			&img->endian);
}

/*
 This program implements the following features:

	- a key is pressed, it will print the key code in the terminal.

	- the mouse if moved, it will print the current position of that mouse
	in the terminal. ### NOT WORKING !!!

	- a mouse is pressed, it will print the angle at which it moved over the 
	window to the terminal. ### NOT WORKING !!!
	
*/
int	main(void)
{
	t_app	app;
	t_img	img;

	init(&app, &img);
	configure_hooks(&app);
	mlx_mouse_get_pos(app.mlx_ptr, app.win_ptr,
		&app.x_cursor_start, &app.y_cursor_start);
	if (DEBUG)
		printf("DEBUG: Initial mouse position:\t(x = %d, y = %d)\n",
			app.x_cursor_start, app.y_cursor_start);
	mlx_loop(app.mlx_ptr);
	return (0);
}
