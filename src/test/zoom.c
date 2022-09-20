/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:40:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/09/20 16:44:54 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 pixel (0,0) == complex number (Im max, Re min)
 	is the top left corner of the window 
	
 pixel (WIDTH, HEIGHT) == complex number (Im min, Re max)
 	is the bottom right corner of the window 
*/
t_complex	pixel2complex(int x, int y)
{
	t_complex	result;

	result.re = (-(double)WIDTH / 2 + (double)x) / (double)WIDTH
		* (info()->re_max - info()->re_min);
	result.im = ((double)HEIGHT / 2 - (double)y) / (double)HEIGHT
		* (info()->im_max - info()->im_min);
	return (result);
}

// Issue: the zoom is not centered on the mouse position
void	center(int x, int y)
{
	t_complex	cursor;

	cursor = (t_complex){pixel2complex(x, y).re, pixel2complex(x, y).im};
	puts("===== TRYING TO CENTER ====");
	printf("CURRENT limits:\n");
	printf("re min\t(%f)\n", info()->re_min);
	printf("re max\t(%f)\n", info()->re_max);
	printf("im_min\t(%f)\n", info()->im_min);
	printf("im_max\t(%f)\n", info()->im_max);
	puts("Mouse coordinates:");
	printf("x = (%d), y = (%d)\n", x, y);
	printf("Re = (%f), Im = (%f)\n", cursor.re, cursor.im);
     //double interpolation = 1.0 / zoomFactor;

/* Move (x,y) to be (0,0) */
	// info()->re_min += cursor.re;
	// info()->re_max += cursor.re;
	// info()->im_min += cursor.im;
	// info()->im_max += cursor.im;

	puts("Computing...");
	
	info()->re_min += cursor.re / 2;
	info()->re_max += cursor.re / 2;
	info()->im_min += cursor.im / 2;
	info()->im_max += cursor.im / 2;
	
	printf("NEW limits:\n");
	printf("re min\t(%f)\n", info()->re_min);
	printf("re max\t(%f)\n", info()->re_max);
	printf("im_min\t(%f)\n", info()->im_min);
	printf("im_max\t(%f)\n", info()->im_max);
	/*
	info()->re_min = (double)mouse_x / (WIN_L / (e->Re.max - e->Re.min)) + e->Re.min;
	info()->re_max /= 3.0f;
	info()->im_min /= 3.0f;
	info()->im_max /= 3.0f;*/
	puts("===== END === TRYING TO CENTER ====");
}

void	zoom_in(int x, int y)
{
	if (DEBUG)
		puts("Zoom in - start");
	center(x, y);
	info()->re_min /= 1.01f;
	info()->re_max /= 1.01f;
	info()->im_min /= 1.01f;
	info()->im_max /= 1.01f;
	draw();
	if (DEBUG)
		puts("Zoom in - end");
}

void	zoom_out(int x, int y)
{
	if (DEBUG)
		puts("Zoom out - start");
	center(x, y);
	info()->re_min *= 1.01f;
	info()->re_max *= 1.01f;
	info()->im_min *= 1.01f;
	info()->im_max *= 1.01f;
	draw();
	if (DEBUG)
		puts("Zoom out - end");
}
