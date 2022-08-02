/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:27:35 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/02 14:40:00 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_motion(int aaa, int x, int y, void *param)
{
	(void)aaa;
	(void)x;
	(void)y;
	(void)param;
	puts("Mouse just moved!");
	return (0);
}

static int	handle_expose(int aaa, int x, int y, void *param)
{
	(void)aaa;
	(void)x;
	(void)y;
	(void)param;
	puts("Window is now exposed!");
	return (0);
}

void	configure_hooks(t_app *app, t_img *img)
{

	mlx_expose_hook(app->win_ptr, handle_expose, &app);
	mlx_hook(app->mlx_ptr, MotionNotify, 1337, handle_motion, &app);
	mlx_hook(app->win_ptr, ButtonPress, ButtonPressMask, handle_mouse, &img);
	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask, handle_keys, &app);
	mlx_hook(
		app->win_ptr, DestroyNotify, StructureNotifyMask, exit_program, &app);
}
