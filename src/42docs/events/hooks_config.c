/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:32:51 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 10:38:23 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

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
	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask,
		hook_action_key_pressed_released, &app);
	mlx_hook(app->win_ptr, KeyPress, KeyPressMask,
		hook_action_key_pressed, &app);
	mlx_hook(app->win_ptr, DestroyNotify, StructureNotifyMask,
		hook_action_x_window_pressed, &app);
	mlx_hook(app->win_ptr, ButtonPress, ButtonPressMask,
		hook_action_button_pressed, &app);
	mlx_hook(app->win_ptr, EnterNotify, EnterWindowMask,
		hook_action_enter_window, &app);
	mlx_hook(app->win_ptr, LeaveNotify, LeaveWindowMask,
		hook_action_leave_window, &app);
	mlx_loop_hook(app->mlx_ptr, next_frame, &app);
}
