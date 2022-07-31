/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:06:57 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/31 16:04:42 by pvaladar         ###   ########.fr       */
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
	//int	 c;
	//char	buffer;
	double MinRe = -3.0f;
	double MaxRe = 3.0f;
	double MinIm = -2.0f;
	double MaxIm = 2.0f;
	double Re_factor = (MaxRe-MinRe)/(WIDTH-1);
	double Im_factor = (MaxIm-MinIm)/(HEIGHT-1);
	unsigned MaxIterations = 100;
	unsigned int	n;

	y = 0;
	//c = HEIGHT;
	while (y < HEIGHT)
	{
		double c_im = MaxIm - y*Im_factor;

		x = 0;
		while (x < WIDTH)
		{
			double c_re = MinRe + x*Re_factor;
			double Z_re = c_re, Z_im = c_im;
			bool isInside = true;
			n = 0;
			while (n<MaxIterations)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
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
				//mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FFFFFF); 
			}
			else
				fast_mlx_pixel_put(img, x, y, 0x000000FF + n*n*n*n);

			// z = 0 ; c = 0
			// z_n+1 = zn * zn + c
			//if ()
			//if ((x - WIDTH / 2) * (x - WIDTH / 2) + (y - HEIGHT / 2) * (y - HEIGHT / 2) == 500)
			x++;
		}
		y++;
	}
}


