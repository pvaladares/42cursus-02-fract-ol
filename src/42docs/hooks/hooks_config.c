/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:32:51 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 12:52:56 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

/*
 Register to catch all keys pressed on Release:
 	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask, ...)
 Could be implemented to catch on Press:
	mlx_hook(app->win_ptr, KeyPress, KeyPressMask, ...)

TODO:
 Register to catch when mouse moves
*/
void	configure_hooks(t_app *app)
{
	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask,
		hook_action_key_pressed_released, &app);
	mlx_hook(app->win_ptr, ButtonPress, ButtonPressMask,
		hook_action_button_pressed, &app);
	mlx_hook(app->mlx_ptr, 6, 0,
		hook_action_mouse_moved, &app);
	mlx_loop_hook(app->mlx_ptr, next_frame, &app);
}
