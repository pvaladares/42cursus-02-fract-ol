/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:51:06 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/02 17:09:25 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 Colour library heavily inspired by 42docs
 https://harm-smits.github.io/42docs/libs/minilibx/colors.html

 Note: Current implementation assumes the colour representation is always
 as per man page `mlx_pixel_put`: TTRRGGBB
*/

/*
 Function that accepts a colour (int) as argument and inverts
 the colour accordindly, transparency is ignored
 e.g. 00112233 goes 00EEDDCC
 Check online: https://pinetools.com/invert-color
*/
int	color_get_opposite(int trgb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = color_get_t(trgb);
	r = 0xFF - color_get_r(trgb);
	g = 0xFF - color_get_g(trgb);
	b = 0xFF - color_get_t(trgb);
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
 Function accepts a distance (double) and a color (int) as arguments
 0 will add no shading to the color, whilst 1 will make the color completely 
 dark. 
 0.5 will dim it halfway, and .25 a quarter way.
 In a nutsheel:
 	distance : between 0 ( = no shading) and 1 (= dark)
*/
int	color_add_shape(double distance, int trgb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = color_get_t(trgb);
	r = (int)(color_get_r(trgb) * distance);
	g = (int)(color_get_g(trgb) * distance);
	b = (int)(color_get_b(trgb) * distance);
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
 Function to implement a smooth transiction between color bands
 We have implemented the method described in [Sil13]. This method uses a slight
modification of Bernstein polynomials to achieve a continuous coloring scheme. We use three polynomials
to map each color channel to a value in [ 0, 255 ] , see Figure 3.3. Because the three polynomials ‘flow’ into
each other, the color will smoothly transition to the next one when iterating over t. The formulas for the
polynomials are
r ( t ) = 9 ∗ ( 1 − t ) ∗ t 3 ∗ 255
g ( t ) = 15 ∗ ( 1 − t ) 2 ∗ t 2 ∗ 255
b ( t ) = 8.5 ∗ ( 1 − t ) 3 ∗ t ∗ 255
*/
int	color_bernstein_polynomials1(double t)
{
	int raw_color;

	raw_color = color_get_trgb(0, 
						(int)(9 * ( 1 - t ) * t * t * t  * 255),
						(int)(15 * ( 1 - t ) * t * t * 255),
						(int)(8.5 * ( 1 - t ) * t * 255)
						);
	return (raw_color % 0xFFFFFF);
	
}

int	color_bernstein_polynomials2(double t)
{
	return(
		color_get_trgb(
						0, 
						(int)(8.5 * ( 1 - t ) * t * 255),
						(int)(9 * ( 1 - t ) * t * t * t  * 255),
						(int)(15 * ( 1 - t ) * t * t * 255)
						)
		);
}

int	color_bernstein_polynomials3(double t)
{
	return(
		color_get_trgb(
						0, 
						(int)(15 * ( 1 - t ) * t * t * 255),
						(int)(8.5 * ( 1 - t ) * t * 255),
						(int)(9 * ( 1 - t ) * t * t * t  * 255)
						)
		);
}
