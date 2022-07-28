/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:27:56 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/28 15:53:07 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	close_app(t_app *app)
{
	//mlx_destroy_window(app->mlx, app->win_ptr);
//	mlx_destroy_display(app->mlx)
//	mlx_destroy_image()
	(void)app;
	exit(EXIT_SUCCESS);
}

/*
 This function closes the window in a safe way whenever the 
 cross on the window (X) is pressed
*/
int	close_window_cross_window(t_app *app)
{
	(void)app;
	close_app(app);
	return (0);
}

/*
 This function closes the window and quits the program in a clean way
 whenever the ESC key is pressed
*/
int	close_window_esc_key(int keycode, t_app *app)
{
	if (keycode == XK_Escape)
		close_app(app);
	else if (keycode == XK_Left)
		puts("Left");
	else if (keycode == XK_Right)
		puts("Right");
	else if (keycode == XK_Up)
		puts("Up");
	else if (keycode == XK_Down)
		puts("Down");
	else
	{
		printf("Pressed key %d %c\n", keycode, keycode);
		//char str[] = "Hello";
		//mlx_string_put(app->mlx, app->win_ptr, 0, 0, 0x00FF0000, str);
		//my_mlx_pixel_put(app, 0, 0, 0x00FF0000);
		//mlx_string_put(app->mlx, app->win_ptr, WIDTH / 2, HEIGHT / 2, 
		//	0x00FF0000, "Hello");
	}
	return (0);
}

// Button4 == Scrool up
// Button5 == Scrool down
int	mouse_hook(int button, int x, int y, t_app *app)
{
	if (button == XK_Pointer_Button4)
		puts("4 - Zoom in");
	else if (button == XK_Pointer_Button5)
		puts("5 - Zoom out");
	(void)app;
	puts("Entered mouse hook");
	printf("Coordinates x = %d , y = %d\n", x, y);
	return (0);
}


