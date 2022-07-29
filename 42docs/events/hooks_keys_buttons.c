/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keys_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:37:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 23:32:57 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

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
	return (0);
}

/*
 Function that will run when any key is pressed and then released
*/
int	hook_action_key_pressed_released(int keycode, t_app *app)
{
	app->key_flag_released = 1;
	if (keycode == XK_Escape)
		exit(EXIT_SUCCESS);
	return (0);
}

/*
 Function that will run when any key is pressed only
*/
int	hook_action_key_pressed(int keycode, t_app *app)
{
	(void)keycode;
	app->key_flag_released = 0;
	app->key_time_pressed = time(NULL);
	return (0);
}

/*
 Function that will run when any mouse button is pressed
*/
int	hook_action_button_pressed(int button, int x, int y, t_app *app)
{
	(void)app;
	return (
		printf("Pressed button: (%d) @ (x = %d, y = %d)\n", button, x, y));
}
