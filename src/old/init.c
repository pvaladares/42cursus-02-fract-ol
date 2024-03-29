/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:48:43 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/02 17:16:02 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_app *app, t_img *img)
{
	app->mlx_ptr = mlx_init();
	if (!app->mlx_ptr)
	{
		perror("Error with mlx_init()");
		exit(EXIT_FAILURE);
	}
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!app->win_ptr)
	{
		perror("Error with mlx_new_window()");
		exit(EXIT_FAILURE);
	}
	img->img_ptr = mlx_new_image(app->mlx_ptr, WIDTH, HEIGHT);
	if (!img->img_ptr)
	{
		perror("Error with mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	img->addr = (int *)mlx_get_data_addr(
			img->img_ptr,
			&img->bits_per_pixel, &img->line_length, &img->endian);

	img->re_min = -1.50f;
	img->re_max = 1.50f;
	img->im_max = 1.50f;

	app->img_ptr = img;
}
