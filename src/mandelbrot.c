/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:06:57 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/31 15:26:04 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// re = a
// im = b
// z = a + b *i
/*
static t_complex	complex_create(long double re, long double im)
{
	t_complex	z;

	z.a = re;
	z.b = im;
	return (z);
}
*/
// z = a + b*i
// z * z = (a + b*i)^2 = (a*a + 2 * a * b * i + b * b * i* i)
// a * a + 2 * a * b * i - b*b
// Re = a * a - b * b
// Im = 2 * a * b
// http://xahlee.info/cmaci/fractal/mandelbrot.html
/*
static t_complex	complex_pow2(t_complex z)
{
	t_complex	result;

	result.a = pow(z.a, 2) - pow(z.b, 2);
	result.b = 2 * z.a * z.b;
	return (result);
}
*/
/*
static t_complex	complex_add(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.a = z1.a + z2.a;
	result.b = z1.b + z2.b;
	return (result);
}
*/

/*
 Function computes |z|
*/
/*
static long double	complex_hypot(t_complex z)
{
	return (hypot(z.a, z.b));
}
*/
/*
fc(z) = z*z + c
if c = 1

	f1(0) = 0*0 + 1 = 1
	f1(1) = 1*1 + 1 = 2
	f1(2) = 2*2 + 1 = 5
	f1(5) = 5*5 + 1 = 26

*/

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

void	create_mandelbrot(t_img *img)
{
	int	 x, y;
	//int	 c;
	//char	buffer;
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*HEIGHT/WIDTH;
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
				fast_mlx_pixel_put(img, x, y, 0x000000FF + n*n*n*n*n);

			// z = 0 ; c = 0
			// z_n+1 = zn * zn + c
			//if ()
			//if ((x - WIDTH / 2) * (x - WIDTH / 2) + (y - HEIGHT / 2) * (y - HEIGHT / 2) == 500)
			x++;
		}
		y++;
	}
}


