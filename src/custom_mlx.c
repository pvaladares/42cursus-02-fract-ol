/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:30:38 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/28 10:34:18 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
https://github.com/keuhdall/images_example/blob/master/example.c
*/
void	fast_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	x += WIDTH / 2;
	y += HEIGHT / 2;
	img->addr[y * WIDTH + x] = color;
}
