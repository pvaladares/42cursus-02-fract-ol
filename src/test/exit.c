/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:02:33 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/04 13:03:06 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	safe_quit()
{
	if (info()->img_ptr)
	{
		mlx_destroy_image(info()->mlx_ptr, info()->img_ptr);
		info()->img_ptr = NULL;
	}
	if (info()->win_ptr)
	{
		mlx_destroy_window(info()->mlx_ptr, info()->win_ptr);
		info()->win_ptr = NULL;
	}
	if (info()->mlx_ptr)
	{
		mlx_destroy_display(info()->mlx_ptr);
		info()->mlx_ptr = NULL;
	}
	exit(EXIT_SUCCESS);
	return (0);
}

