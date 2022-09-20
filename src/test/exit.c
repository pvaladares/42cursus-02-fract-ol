/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:02:33 by pvaladar          #+#    #+#             */
/*   Updated: 2022/09/20 16:43:14 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 This function frees all the allocated memory and closes the program in a safe
 and clean way using the mlx_destroy family of functions
*/
int	safe_quit(void)
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
