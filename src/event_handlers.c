/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:27:56 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/30 18:37:26 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 This function closes the window and quits the program in a clean way
 whenever the ESC key is pressed
*/
int	handle_keys(int keycode, t_app *app)
{
	(void)app;
	if (keycode == XK_Escape)
		exit_program();
	else if (keycode == XK_Left)
		puts("Left");
	else if (keycode == XK_Right)
		puts("Right");
	else if (keycode == XK_Up)
		puts("Up");
	else if (keycode == XK_Down)
		puts("Down");
	else if (DEBUG)
		printf("Pressed key %d %c\n", keycode, keycode);
		//char str[] = "Hello";
		//mlx_string_put(app->mlx, app->win_ptr, 0, 0, 0x00FF0000, str);
		//my_mlx_pixel_put(app, 0, 0, 0x00FF0000);
		//mlx_string_put(app->mlx, app->win_ptr, WIDTH / 2, HEIGHT / 2, 
		//	0x00FF0000, "Hello");
	return (0);
}

// Button4 == Scrool up
// Button5 == Scrool down
int	handle_mouse(int button, int x, int y, t_app *app)
{
	if (button == XK_Pointer_Button4)
		puts("4 - Zoom in / Scroll up");
	else if (button == XK_Pointer_Button5)
		puts("5 - Zoom out / Scrool down");
	else if (button == XK_Pointer_Button1)
		puts("1 - Left");
	else if (button == XK_Pointer_Button2)
		puts("2 - Right");
	else if (button == XK_Pointer_Button3)
		puts("3 - Middle");
	(void)app;
	printf("Coordinates x = %d , y = %d\n", x, y);
	return (0);
}


