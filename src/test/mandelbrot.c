/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:01:02 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/04 13:01:11 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_mandelbrot(void)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;
	t_complex	z;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z = (t_complex){0.0f, 0.0f};
			c.re = info()->re_min + (x * info()->x_ratio);
			c.im = info()->im_max - (y * info()->y_ratio);
			i = 0;
			while (z.re < 2 && z.im < 2 && ++i < info()->max_iterations)
			{
				if (z.re * z.re + z.im * z.im >= 4)
					break ;
				z = complex_add(complex_pow2(z), c);
			}
			set_color(x, y, i);
		}
	}
}
