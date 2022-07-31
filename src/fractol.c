/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:14:11 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/31 16:03:14 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_next_frame(t_app *app)
{
	//int x, y;

	(void)app;
	puts("Rendering next frame...");
	//mlx_mouse_get_pos(self.mlx_ptr, self.win_ptr, &x , &y);
	//printf("Coordinates x = %d , y = %d\n", x, y);
	return (0);
}

int	exit_program(void)
{
	exit(EXIT_SUCCESS);
}

/*
 Create mlx instance
 Create window instance
 Create image instance
 Get the image address and use custom put function to write without showing it
 Render the image
*/

#include <math.h>

int	main(int argc, char **argv)
{
	t_app	app;
	t_img	img;
	int		x;
	int		y;

	/*
	t_complex	c;

	c.a = 2.0;
	c.b = 2.0;
	printf("Norm of (%Lf) with (%Lf) equals (%f)\n", c.a, c.b, hypot(c.a, c.b));
*/
	(void)(argv);
	if (argc != 3)
	{
		printf("\e[31m## error - incorrect syntax ##\n\e[0m");
		printf(
			"\e[92m./fractol <fractal-number | fractal-name or> [<optional parameters>]\n\e[0m");
		return (EXIT_FAILURE);
	}
	fractol_init(&app, &img);
	create_mandelbrot(&img);
	configure_hooks(&app);

	// show Re and Im axis
	y = 0;
	while (y < HEIGHT)
			fast_mlx_pixel_put(&img, WIDTH / 2, y++, 0x00FF0000);
	x = 0;
	while (x < WIDTH)
			fast_mlx_pixel_put(&img, x++, HEIGHT / 2, 0x00FF0000);
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, img.img_ptr, 0, 0);
	
	//mlx_do_sync(app.mlx_ptr);
	//mlx_loop_hook(app.mlx_ptr, render_next_frame, &app);
	mlx_loop(app.mlx_ptr);
	return (EXIT_SUCCESS);
}

// Go full screen ??