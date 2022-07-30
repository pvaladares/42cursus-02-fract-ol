/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:51:06 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/30 17:09:30 by pvaladar         ###   ########.fr       */
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
int	colour_get_opposite(int trgb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = colour_get_t(trgb);
	r = 0xFF - colour_get_r(trgb);
	g = 0xFF - colour_get_g(trgb);
	b = 0xFF - colour_get_t(trgb);
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
int	colour_add_shape(double distance, int trgb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = colour_get_t(trgb);
	r = (int)(colour_get_r(trgb) * distance);
	g = (int)(colour_get_g(trgb) * distance);
	b = (int)(colour_get_b(trgb) * distance);
	return (t << 24 | r << 16 | g << 8 | b);
}
