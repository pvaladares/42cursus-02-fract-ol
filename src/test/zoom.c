/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:40:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/06 02:23:55 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pixel2complex(int x, int y)
{
	t_complex	result;

	result.re = (double)x
		/ (WIDTH / (info()->re_max - info()->re_min)) + info()->re_min;
	result.im = -((double)y
			/ (HEIGHT / (info()->im_max - info()->im_min)) + info()->im_min);
	return (result);
}

void	center(int x, int y)
{
	t_complex	cursor;

	cursor = (t_complex){pixel2complex(x, y).re, pixel2complex(x, y).im};
	puts("===== TRYING TO CENTER ====");
	printf("x = (%d), y = (%d)\n", x, y);
	printf("Re = (%f), Im = (%f)\n", cursor.re, cursor.im);
     //double interpolation = 1.0 / zoomFactor;
	draw();
	info()->re_min -= cursor.re;
	info()->re_max -= cursor.re;
	info()->im_min += cursor.im;
	info()->im_max += cursor.im;
	/*
	info()->re_min = (double)mouse_x / (WIN_L / (e->Re.max - e->Re.min)) + e->Re.min;
	info()->re_max /= 3.0f;
	info()->im_min /= 3.0f;
	info()->im_max /= 3.0f;*/
	puts("===== END === TRYING TO CENTER ====");

}

void	zoom_in(int x, int y)
{
	(void)x;
	(void)y;
	info()->re_min /= 3.0f;
	info()->re_max /= 3.0f;
	info()->im_min /= 3.0f;
	info()->im_max /= 3.0f;
	draw();
	puts("Hello zoom!");
}
