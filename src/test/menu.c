/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:06:30 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/04 14:27:23 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static draw_menu(void)
{
	int	x;
	int	y;

	x = WIDTH;
	while (x < WIDTH + MENU_WIDTH)
	{
		y = 0;
		while (y < 100)
		{	
			
		}
		y++;		
	}
}


void	display_text(void)
{
	const int	spacing = 15;
	//const int	helper_width = WIDTH + HELPER_SIZE;

		mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 1, WHITE, "INFORMATIONS");
		mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 2, WHITE, "  Fractal: Mandelbrot");
		mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 3, WHITE, "CONTROLS");
		mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 4, WHITE, "Iterations++: +");

}


