/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:06:57 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/02 14:20:58 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
static int	is_unstable(t_complex number, int iterations)
{
	int			i;

	i = 1;
	while (i < iterations)
	{
		number = complex_add(complex_pow2(number), number);
		if (complex_hypot(number) > 2.0f)
			return (i);
		i++;
	}
	return (0);
}*/

#include <stdbool.h>

/*
 Usually, the ‘x’ value ranges from -3 to +3, and the ‘y’ value ranges from -2 to +2.
https://javalab.org/en/mandelbrot_set_en/

https://github.com/sisittu99/fract-ol/blob/master/README_EN.md
*/
void	create_mandelbrot(t_img *img)
{
	int	 x, y;
	t_complex c;
	t_complex z;

	int n;
	int color;
	float t;
	/*
	double im_min = -2.0f;
	double re_factor = (re_max-re_min)/(WIDTH-1);
	double im_factor = (im_max-im_min)/(HEIGHT-1);
	unsigned MaxIterations = 100;
	unsigned int	n;
*/

	double pixel_size = (img->re_max - img->re_min) / WIDTH;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = img->re_min+ (x * pixel_size);
			c.im = img->im_max - (y * pixel_size);
			z.re = 0.0f;
			z.im = 0.0f;
			n = 1;
			while (n < NMAX)
			{
				if (complex_norm(z) > 2)
					break;
				z = complex_add(complex_pow2(z), c);
				n++;
			}
			if ( DEBUG && (c.re == 0.0f || c.im == 0.0f)) // draw axis after convert from pixels to point
				fast_mlx_pixel_put(img, x, y, 0x00FF0000);
			else
			{
				t = (float)n / NMAX;
				color = color_bernstein_polynomials(t);
				fast_mlx_pixel_put(img, x, y, color);
			}
			x++;
		}
		y++;
	}

/*
	y = 0;
	while (y < HEIGHT)
	{
		double c_im = im_max - y*im_factor;

		x = 0;
		while (x < WIDTH)
		{
			double c_re = re_min + x*re_factor;
			double Z_re = c_re, Z_im = c_im;
			bool isInside = true;
			n = 0;
			while (n<MaxIterations)
			{
				double Z_re2 = Z_re*Z_re;
				double Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					isInside = false;
					break;
				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
				n++;
			}
			if (isInside)
			{ 
				fast_mlx_pixel_put(img, x, y, 0x00FFFFFF);
			}
			else
				fast_mlx_pixel_put(img, x, y, 0x000000FF + n*n*n*n);
			x++;
		}
		y++;
	}
	*/
}


