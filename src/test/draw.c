/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:04:23 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/06 02:28:52 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void set_color(int x, int y, int i)
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
	else if (i == info()->max_iterations)
		fast_mlx_pixel_put(x, y, BLACK);
	else
	{
		t = (double)i / MAX_ITERATIONS;
		color = color_bernstein_polynomials1(t);
		fast_mlx_pixel_put(x, y, color);
	}
}

void	draw(void)
{
	int	x;
	int	y;
	int	iterations;

	mlx_clear_window(info()->mlx_ptr, info()->win_ptr);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			iterations = fractal_mandelbrot(x, y);
			set_color(x, y, iterations);
		}
	}
	//display_text();
	mlx_put_image_to_window(info()->mlx_ptr, info()->win_ptr,
		info()->img_ptr, 0, 0);
	//fast_mlx_pixel_put(WIDTH / 2, HEIGHT / 2, 0x00FF0000);
}
