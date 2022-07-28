/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:58:20 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/28 17:52:19 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <time.h> // time()
#include <stdio.h> // NULL definition, printf(), puts()

/*
 Function sends a message to terminal after pressing a key longer than 1 seconds
*/
int	check_key_pressed_not_released(t_app *app)
{
	time_t	seconds_key_pressed_not_released;

	if (app->key_flag_released == 0)
	{
		seconds_key_pressed_not_released = time(NULL) - app->key_time_pressed;
		if (seconds_key_pressed_not_released >= 1)
		{
			puts("Reminder... please, don't forget to release the key!");
			app->key_flag_released = 1;
		}
	}
}

int	next_frame(t_app *app)
{
	check_key_pressed_not_released(app);
}

/*
 Function that will run when any key is pressed and then released
*/
int	hook_action_key_pressed_released(int keycode, t_app *app)
{
	app->key_flag_released = 1;
	printf("Pressed key: \t(%d)\t(%c)\n", keycode, keycode);
	if (keycode == XK_Escape)
		exit(EXIT_SUCCESS);
}

/*
 Function that will run when any key is pressed only
*/
int	hook_action_key_pressed(int keycode, t_app *app)
{
	app->key_flag_released = 0;
	app->key_time_pressed = time(NULL);
}

/*
 Function that will run when the red X window button is pressed
*/
int	hook_action_x_window_pressed(t_app *app)
{
	exit(EXIT_SUCCESS);
}

/*
 Function that will run when any mouse button is pressed
*/
int	hook_action_button_pressed(int button, int x, int y, t_app *app)
{
	printf("Pressed button: (%d) @ (x = %d, y = %d)\n", button, x, y);
}

int	hook_action_enter_window(int button, int x, int y, t_app *app)
{
	(void)button;
	(void)x;
	(void)y;
	(void)app;

	printf("Hello!\n");
}

int	hook_action_leave_window(int button, int x, int y, t_app *app)
{
	(void)button;
	(void)x;
	(void)y;
	(void)app;

	printf("Bye!\n");
}

/*
 Register to catch all keys pressed on Release:
 	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask, ...)
 Could be implemented to catch on Press:
	mlx_hook(app->win_ptr, KeyPress, KeyPressMask, ...)

 Register to catch when the "X red window button" is pressed
	mlx_hook(app->win_ptr, DestroyNotify, StructureNotifyMask, ...)
*/
void	configure_hooks(t_app *app)
{
	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask, hook_action_key_pressed_released, &app);
	mlx_hook(app->win_ptr, KeyPress, KeyPressMask, hook_action_key_pressed, &app);

	mlx_hook(app->win_ptr, DestroyNotify, StructureNotifyMask, hook_action_x_window_pressed, &app);
	mlx_hook(app->win_ptr, ButtonPress, ButtonPressMask, hook_action_button_pressed, &app);
	mlx_hook(app->win_ptr, EnterNotify, EnterWindowMask, hook_action_enter_window, &app);
	mlx_hook(app->win_ptr, LeaveNotify, LeaveWindowMask, hook_action_leave_window, &app);

	mlx_loop_hook(app->mlx_ptr, next_frame, &app);
}

int	main(void)
{
	t_app	app;
	t_img	img;

	app.mlx_ptr = mlx_init();
	if (!app.mlx_ptr)
	{
		perror("Error with mlx_init()");
		exit(EXIT_FAILURE);
	}
	app.win_ptr = mlx_new_window(app.mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!app.win_ptr)
	{
		perror("Error with mlx_new_window()");
		exit(EXIT_FAILURE);
	}
	img.img_ptr = mlx_new_image(app.mlx_ptr, WIDTH, HEIGHT);
	if (!img.img_ptr)
	{
		perror("Error with mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	img.addr = (int *)mlx_get_data_addr(
			img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	//mlx_do_key_autorepeatoff(app.mlx_ptr); // Set by default
	configure_hooks(&app);
	//app.key_flag_released = 0;
	mlx_loop(app.mlx_ptr);
}
