/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:27:35 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/28 15:46:16 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	configure_hooks(t_app *app)
{
	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask,
		close_window_esc_key, &app);
	mlx_hook(app->win_ptr, DestroyNotify, StructureNotifyMask,
		close_window_cross_window, &app); // X
	mlx_hook(app->win_ptr, ButtonPress, ButtonPressMask,
		mouse_hook, &app); // Mouse scrool
}
