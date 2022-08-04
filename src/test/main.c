/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:13:37 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/04 16:02:04 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*contains information about the mlx pointers and windows*/
t_app	*info(void)
{
	static t_app	info;

	return (&info);
}

int	main(void)
{
	initialize_variables();
	draw();
	display_text();
	/* Hooks */
	mlx_hook(info()->win_ptr, KeyRelease, KeyReleaseMask, key_released, NULL);
	mlx_hook(info()->win_ptr, ButtonPress, ButtonPressMask, mouse_button_pressed, NULL);
	mlx_hook(info()->win_ptr, DestroyNotify, StructureNotifyMask, safe_quit, NULL);
	mlx_hook(info()->win_ptr, MotionNotify, PointerMotionMask, mouse_moved, NULL);

	/* End Hooks */
	mlx_loop(info()->mlx_ptr);
	return (0);
}
