/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:01:02 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/06 01:51:16 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_mandelbrot(int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			i;

	z = (t_complex){0.0f, 0.0f};
	c = pixel2complex(x, y);
	i = 1;
	while (z.re < 2 && z.im < 2 && i < info()->max_iterations)
	{
		if (pow(z.re, 2) + pow(z.im, 2) >= 4)
			break ;
		z = complex_add(complex_pow2(z), c);
		i++;
	}
	return (i);
}
