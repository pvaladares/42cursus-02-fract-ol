/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 01:38:56 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/06 01:40:39 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hooks(void)
{
	mlx_hook(info()->win_ptr, KeyRelease, KeyReleaseMask, key_released,
		NULL);
	mlx_hook(info()->win_ptr, ButtonPress, ButtonPressMask, mouse_pressed,
		NULL);
	mlx_hook(info()->win_ptr, DestroyNotify, StructureNotifyMask, safe_quit,
		NULL);
	mlx_hook(info()->win_ptr, MotionNotify, PointerMotionMask, mouse_moved,
		NULL);
}
