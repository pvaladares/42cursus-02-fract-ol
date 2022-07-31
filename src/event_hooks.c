/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:27:35 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/31 00:13:58 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	motion_hook(int aaa, int x, int y, void *param)
{
	(void)aaa;
	(void)x;
	(void)y;
	(void)param;
	puts("Something is movingg..");
	return (0);
}


void	configure_hooks(t_app *app)
{

	mlx_expose_hook(app->win_ptr, motion_hook, &app);
	mlx_hook(app->mlx_ptr, 6, 64, motion_hook, &app);
	mlx_hook(app->win_ptr, ButtonPress, ButtonPressMask, handle_mouse, &app);
	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask, handle_keys, &app);
	mlx_hook(
		app->win_ptr, DestroyNotify, StructureNotifyMask, exit_program, &app);
}
