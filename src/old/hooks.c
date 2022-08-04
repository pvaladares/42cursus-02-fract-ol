/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:27:35 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/02 17:07:49 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	configure_hooks(t_app *app)
{

	mlx_hook(app->win_ptr, ButtonPress, ButtonPressMask, handle_mouse, &app);
	mlx_hook(app->win_ptr, KeyRelease, KeyReleaseMask, handle_keys, &app);
	mlx_hook(
		app->win_ptr, DestroyNotify, StructureNotifyMask, exit_program, &app);
}
