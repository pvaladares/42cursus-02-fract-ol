/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:06:57 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/30 19:41:18 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
static t_complex	create_complex(long double x, long double y)
{
	t_complex	number;

	number.a = x;
	number.b = y;
	return (number);
}

// z = a + b*i
// z * z = (a + b*i)^2 = (a*a + 2 * a * b * i + b * b * i* i)
// a * a + a * b * i - b*b
// Re = a * a - b * b
// Im = a * b
static long double	hypot_complex(t_complex *number)
{
	long double	real;
	long double	imaginary;

	real = pow(number->a, 2) - pow(number->b, 2);
	imaginary = number->a * number->b;
	return (hypot(real, imaginary));
}

static int	is_unstable(t_complex number, int iterations)
{
	int			i;

	i = 0;
	while (i < iterations)
	{
		if (hypot_complex(&number) > 2.0f)
			return (i);
		i++;
	}
	return (0);
}
*/

void	create_mandelbrot(t_img *img)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x > WIDTH / 2)
				fast_mlx_pixel_put(img, x, y, 0x00FF00FF);
			else
				fast_mlx_pixel_put(img, x, y, 0x00000FF0);
			/*
			if (is_unstable(create_complex(x, y), 10000) == 0)
				fast_mlx_pixel_put(img, x, y, 0x00FF0000);
			else
				fast_mlx_pixel_put(img, x, y, 0x00000FF0);
			*/
			x++;
		}
		y++;
	}
}
