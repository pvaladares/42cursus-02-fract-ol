/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:04:23 by pvaladar          #+#    #+#             */
/*   Updated: 2022/09/20 16:25:58 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 This function sets the color of the pixel according to the number of iterations
 required to escape the set
*/
static void	set_color(int x, int y, int i)
{
	int			color;
	double		t;

	if (DEBUG && (x == WIDTH / 2 || y == HEIGHT / 2))
	{
		fast_mlx_pixel_put(x, y, 0x00FF0000);
		mlx_string_put(info()->mlx_ptr, info()->win_ptr, 0, HEIGHT / 2, RED, "Re Min");
		mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH - 50, HEIGHT / 2, RED, "Re Max");
		mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH / 2, HEIGHT / 2, RED, "(0, 0)");
		mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH / 2, HEIGHT - 10, RED, "Im Min");
		mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH / 2, 10, RED, "Im Max");
	}
	else if (i >= info()->max_iterations)
		fast_mlx_pixel_put(x, y, RED);
	else
	{
		t = (double)i / MAX_ITERATIONS;
		color = color_bernstein_polynomials1(t);
		fast_mlx_pixel_put(x, y, color);
	}
}

/*
 Function clears the window, loops through all the pixels and calls the
 function to set the color of each pixel according to the fractal chosen, 
 and finally shows the window.
*/
void	draw(void)
{
	int	x;
	int	y;
	int	iterations;

	mlx_clear_window(info()->mlx_ptr, info()->win_ptr);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iterations = fractal_mandelbrot(x, y);
			set_color(x, y, iterations);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info()->mlx_ptr, info()->win_ptr,
		info()->img_ptr, 0, 0);
	display_text();
}
