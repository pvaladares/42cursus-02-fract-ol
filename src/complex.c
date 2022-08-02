/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:39:20 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/02 14:12:02 by pvaladar         ###   ########.fr       */
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
t_complex	complex_pow2(t_complex z)
{
	t_complex	result;

	result.re = pow(z.re, 2) - pow(z.im, 2);
	result.im = 2 * z.re * z.im;
	return (result);
}

/*
 Function adds two complex numbers and returns the resul
*/
t_complex	complex_add(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.re = z1.re + z2.re;
	result.im = z1.im + z2.im;
	return (result);
}

/*
 Function computes |z|
*/
long double	complex_norm(t_complex z)
{
	return (hypot(z.re, z.im));
}

/*
fc(z) = z*z + c
if c = 1

	f1(0) = 0*0 + 1 = 1
	f1(1) = 1*1 + 1 = 2
	f1(2) = 2*2 + 1 = 5
	f1(5) = 5*5 + 1 = 26

*/
