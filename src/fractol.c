/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:14:11 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/25 17:42:43 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <time.h> // random rgb
#include <stdlib.h> // random
#include <unistd.h>


/*
 This function closes the window and quits the program in a clean way
 whenever the ESC key is pressed
*/
int	close_window_esc_key(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == XK_Left)
		puts("Left");
	else if (keycode == XK_Right)
		puts("Right");
	else if (keycode == XK_Up)
		puts("Up");
	else if (keycode == XK_Down)
		puts("Down");
	else
		printf("Pressed key %d %c\n", keycode, keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == Button4)
		puts("4 - Zoom in");
	else if (button == Button5)
		puts("5 - Zoom out");
	(void)vars;
	puts("Entered mouse hook");
	printf("Coordinates x = %d , y = %d\n", x, y);
	return (0);
}

/*
 This function closes the window in a safe way whenever the cross on the window (X)
 is pressed
*/
int	close_window_cross_window(t_vars *vars)
{
	(void)vars;
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

/*
  The bytes are not aligned, this means that the line_length differs from the actual window width.
 We therefore should ALWAYS calculate the memory offset using the line length set by mlx_get_data_addr.

We can calculate it very easily by using the following formula:
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
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
	t_vars	vars;
	t_data	img;
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
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		perror("Error with mlx_init()");
		exit(EXIT_FAILURE);
	}
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello world!");
	if (!vars.win)
	{
		perror("Error with mlx_new_window()");
		exit(EXIT_FAILURE);
	}
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	if (!img.img)
	{
		perror("Error with mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	img.addr = mlx_get_data_addr(
		img.img, &img.bits_per_pixel, &img.line_length, &img.endian);



	y = 0;
	while (y < HEIGHT)
	{
					

		x = 0;
		while (x < WIDTH)
		{
			
			//my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			my_mlx_pixel_put(&img, x, y, (x+y)*1000);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);


	
	mlx_hook(vars.win, KeyRelease, KeyReleaseMask, close_window_esc_key, &vars); // ESC
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, close_window_cross_window, &vars); // X
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, mouse_hook, &vars); // Mouse scrool
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}

// https://en.wikipedia.org/wiki/Mandelbrot_set

