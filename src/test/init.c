/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:03:37 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/06 02:25:50 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_mlx(void)
{
	info()->mlx_ptr = mlx_init();
	if (!info()->mlx_ptr)
	{
		perror("Error with mlx_init()");
		exit(EXIT_FAILURE);
	}
	info()->win_ptr = mlx_new_window(info()->mlx_ptr, WIDTH + MENU_WIDTH, HEIGHT, TITLE);
	if (!info()->win_ptr)
	{
		perror("Error with mlx_new_window()");
		exit(EXIT_FAILURE);
	}
	info()->img_ptr = mlx_new_image(info()->mlx_ptr, WIDTH, HEIGHT);
	if (!info()->img_ptr)
	{
		perror("Error with mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	info()->img_addr = (int *)mlx_get_data_addr(
		info()->img_ptr, &info()->bits_per_pixel, &info()->line_length,
		&info()->endian);
}

void	initialize_variables(void)
{
	info()->re_min = -2.2f;
	info()->re_max = +2.2f;
	info()->im_min = -2.2f;
	info()->im_max = +2.2f;
	//info()->x_ratio = (info()->re_max - info()->re_min) / (double)WIDTH;
	//info()->y_ratio = (info()->im_max - info()->im_min) / (double)HEIGHT;
	if (DEBUG)
	{
		//printf("x ratio: (%f)\n", info()->x_ratio);
		//printf("y ratio: (%f)\n", info()->y_ratio);
	}
	info()->max_iterations = MAX_ITERATIONS;
	info()->fractal_id = 1;
}
