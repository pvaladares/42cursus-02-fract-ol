/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:14:11 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/30 17:28:34 by pvaladar         ###   ########.fr       */
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

/*
 Create mlx instance
 Create window instance
 Create image instance
 Get the image address and use custom put function to write without showing it
 Render the image
*/
int	main(int argc, char **argv)
{
	t_app	app;
	t_img	img;
	int		x;
	int		y;

	(void)(argv);
	if (argc != 3)
	{
		printf("\e[31m## error - incorrect syntax ##\n\e[0m");
		printf(
			"\e[92m./fractol <fractal-number | fractal-name or> [<optional parameters>]\n\e[0m");
		return (EXIT_FAILURE);
	}
	fractol_init(&app, &img);

	x = 0;
	y = 0;
	fast_mlx_pixel_put(&img, x, y, 0x00FF0000);
/*
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			//my_mlx_pixel_put(&img, x, y, (x+y)*1000);
			x++;
		}
		y++;
	}
*/

	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, img.img_ptr, 0, 0);

	configure_hooks(&app);
	//mlx_do_sync(app.mlx_ptr);
	//mlx_loop_hook(app.mlx_ptr, render_next_frame, &app);
	mlx_loop(app.mlx_ptr);
	return (EXIT_SUCCESS);
}
