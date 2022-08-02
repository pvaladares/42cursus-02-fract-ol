/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:27:56 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/02 17:16:53 by pvaladar         ###   ########.fr       */
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
	else if (keycode == XK_Left || keycode == XK_a)
		puts("Left");
	else if (keycode == XK_Right || keycode == XK_d)
		puts("Right");
	else if (keycode == XK_Up || keycode == XK_w)
		puts("Up");
	else if (keycode == XK_Down || keycode == XK_s)
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
	(void)app;
	if (button == Button4)
	{
		puts("4 - Zoom in / Scroll up");
		//img->re_max = 13.37f;
		//printf("Value : (%f)\n");
		
		//mlx_destroy_window()
	///	printf("re_max = %f\n", app->img_ptr->re_max);
		//img->re_max *= 1.1;
		//img->re_min *= 1.1;
		//img->im_max *= 1.1;
		//printf("re_max = %f\n",);
		//mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	}
	else if (button == Button5)
		puts("5 - Zoom out / Scrool down");
	else if (button == Button1)
		puts("1 - Left");
	else if (button == Button2)
		puts("2 - Right");
	else if (button == Button3)
		puts("3 - Middle");
	printf("Button pressed = (%d) , (%c)\n", button, button);
	printf("Coordinates x = %d , y = %d\n", x, y);	
	return (0);
}


