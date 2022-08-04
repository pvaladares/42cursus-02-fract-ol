/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:40:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/04 16:22:51 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	pixel2complex(int x, int y)
{
	t_complex	result;

	result.re = (double)x / (WIDTH / (info()->re_max - info()->re_min)) + info()->re_min;
	result.im = (double)y / (HEIGHT / (info()->im_max - info()->im_min)) + info()->im_min;
	return (result);
}

static double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void	center(int x, int y)
{
	double mouseRe = pixel2complex(x, y).re;
	double mouseIm = pixel2complex(x, y).im;
	
	printf("x = (%d), y = (%d)\n", x, y);
	printf("x = (%f), y = (%f)\n", pixel2complex(x, y).re, pixel2complex(x, y).im);

     //double interpolation = 1.0 / zoomFactor;
     info()->re_min = interpolate(mouseRe, info()->re_min, 1);
     info()->re_max = interpolate(mouseRe, info()->re_max, 1);
     info()->im_min = interpolate(mouseIm, info()->im_min, 1);
     info()->im_max = interpolate(mouseIm, info()->im_max, 1);
	info()->x_ratio = (info()->re_max - info()->re_min) / (double)WIDTH;
	info()->y_ratio = (info()->im_max - info()->im_min) / (double)HEIGHT;
	draw();
	
	/*
	info()->re_min = (double)mouse_x / (WIN_L / (e->Re.max - e->Re.min)) + e->Re.min;
	info()->re_max /= 3.0f;
	info()->im_min /= 3.0f;
	info()->im_max /= 3.0f;*/
}

void	zoom_in(int x, int y)
{
	(void)x;
	(void)y;
	info()->re_min /= 3.0f;
	info()->re_max /= 3.0f;
	info()->im_min /= 3.0f;
	info()->im_max /= 3.0f;
	info()->x_ratio = (info()->re_max - info()->re_min) / (double)WIDTH;
	info()->y_ratio = (info()->im_max - info()->im_min) / (double)HEIGHT;
	draw();
	puts("Hello zoom!");
}
