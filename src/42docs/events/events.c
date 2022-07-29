/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:58:20 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 11:13:03 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

/*
 This routine is executed every loop
*/
int	next_frame(t_app *app)
{
	check_key_pressed_not_released(app);
	return (0);
}

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

	- ESC key is pressed, your window should close.

	- window is resized, you should print something in your terminal.
	===========================================================================
	Note: not implemented since MLX does not allow the window to be resized!
	More info here: 
		https://aurelienbrabant.fr/
		blog/getting-started-with-the-minilibx#Minilibx-window-limitations
	===========================================================================
	
	- the red cross is clicked, your window should close.

	- you press a key longer than x seconds, you should print something
	in your terminal.

	- mouse enters the window, you should print Hello! in your terminal, 
	when it leaves, you should print Bye!.
	
*/
int	main(void)
{
	t_app	app;
	t_img	img;

	init(&app, &img);
	configure_hooks(&app);
	mlx_loop(app.mlx_ptr);
	return (0);
}
