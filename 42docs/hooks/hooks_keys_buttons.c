/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keys_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:37:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 23:21:53 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

/*
 Function that will run when any key is pressed and then released
*/
int	hook_action_key_pressed_released(int keycode, t_app *app)
{
	(void)app;
	printf("Key pressed: (%d)\t(%c)\n", keycode, keycode);
	return (0);
}

/*
 Function that will run when any mouse button is pressed
*/
int	hook_action_button_pressed(int button, int x, int y, t_app *app)
{
	int	delta_x;
	int	delta_y;

	puts("TODO: Calculate angle");
	printf("Pressed button: (%d)\t(x = %d, y = %d)\n", button, x, y);
	printf("Start pos: (%d) (%d)\n", app->x_cursor_start, app->y_cursor_start);
	delta_x = x - app->x_cursor_start;
	delta_y = y - app->y_cursor_start;
	printf(" Delta: (%d) (%d)\n", delta_x, delta_y);
	puts("END TODO");
	return (0);
}

