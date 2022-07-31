/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:39:20 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/31 15:39:21 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
