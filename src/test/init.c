/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:03:37 by pvaladar          #+#    #+#             */
/*   Updated: 2022/09/20 15:58:12 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mlx_configure_img(void)
{
	info()->img_addr = (int *)mlx_get_data_addr(info()->img_ptr,
		&info()->bits_per_pixel, &info()->line_length,
		&info()->endian);
	if (!info()->img_addr)
	{
		perror("Error with mlx_get_data_addr()");
		exit(EXIT_FAILURE);
	}
}

void	create_mlx(void)
{
	info()->mlx_ptr = mlx_init();
	if (!info()->mlx_ptr)
	{
		perror("Error with mlx_init()");
		exit(EXIT_FAILURE);
	}
	info()->win_ptr = mlx_new_window(info()->mlx_ptr, (int)(WIDTH + MENU_WIDTH),
		HEIGHT, TITLE);
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
	mlx_configure_img();
}

void	initialize_variables(void)
{
	info()->re_min = -2.0f;
	info()->re_max = +2.0f;
	info()->im_min = -2.0f;
	info()->im_max = +2.0f;
	//info()->x_ratio = (info()->re_max - info()->re_min) / (double)WIDTH;
	//info()->y_ratio = (info()->im_max - info()->im_min) / (double)HEIGHT;
	if (DEBUG)
	{
		//printf("x ratio: (%f)\n", info()->x_ratio);
		//printf("y ratio: (%f)\n", info()->y_ratio);
	}
	info()->max_iterations = MAX_ITERATIONS;
	//info()->fractal_id = 1;
}
