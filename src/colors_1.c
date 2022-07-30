/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:51:06 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/30 17:09:27 by pvaladar         ###   ########.fr       */
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
 Function returns the integer representation of a colour, taking as input
 each channel: (t)ransparancy, (r)ed, (g)reen and (b)lue
*/
int	colour_get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
 Function retrieves the transparancy channel from the colour
*/
int	colour_get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

/*
 Function retrieves the red channel from the colour
*/
int	colour_get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

/*
 Function retrieves the green channel from the colour
*/
int	colour_get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

/*
 Function retrieves the blue channel from the colour
*/
int	colour_get_b(int trgb)
{
	return (trgb & 0xFF);
}
