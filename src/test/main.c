/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:13:37 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/04 00:47:10 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*contains information about the mlx pointers and windows*/
t_app	*info(void)
{
	static t_app	info;

	return (&info);
}

void	fast_mlx_pixel_put(int x, int y, int color)
{
	info()->img_addr[y * WIDTH + x] = color;
}


void	initialize_variables(void)
{
	info()->re_min = -2.0f;
	info()->re_max = +2.0f;
	info()->im_min = -2.0f;
	info()->im_max = +2.0f;
	info()->x_ratio = (info()->re_max - info()->re_min) / (double)WIDTH;
	info()->y_ratio = (info()->im_max - info()->im_min) / (double)HEIGHT;
	if (DEBUG)
	{
		printf("x ratio: (%f)\n", info()->x_ratio);
		printf("y ratio: (%f)\n", info()->y_ratio);
	}
	create_mlx();
}

void	create_mlx(void)
{
	info()->mlx_ptr = mlx_init();
	if (!info()->mlx_ptr)
	{
		perror("Error with mlx_init()");
		exit(EXIT_FAILURE);
	}
	info()->win_ptr = mlx_new_window(info()->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!info()->win_ptr)
	{
		perror("Error with mlx_new_window()");
		exit(EXIT_FAILURE);
	}
	info()->img_ptr = mlx_new_image(info()->mlx_ptr, WIDTH, HEIGHT);
	if (!info()->img_ptr)
	{
		perror("Error with mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	info()->img_addr = (int *)mlx_get_data_addr(
		info()->img_ptr, &info()->bits_per_pixel, &info()->line_length,
		&info()->endian);
}

int	mouse_button_pressed(int button, int x, int y)
{
	if (DEBUG)
	{
		puts("== ENTERED MOUSE BUTTON PRESSED ==");
		printf("Pressed mouse button:\t(%d)\t(%d)\n", button, button);
		printf("Original cursor coordinates:\t(x = %d, y = %d)\n", x, y);
	}
	if (button == Button4) // Scrool up == Zoom in
		puts("Zoom in");
	else if (button == Button5) // Zoom out
		puts("Zoom out");
	if (DEBUG)
		printf("Correct cursor coordinates:\t(x = %d, y = %d)\n", x, y);
	return (0);
}

int	safe_quit()
{
	if (info()->img_ptr)
	{
		mlx_destroy_image(info()->mlx_ptr, info()->img_ptr);
		info()->img_ptr = NULL;
	}
	if (info()->win_ptr)
	{
		mlx_destroy_window(info()->mlx_ptr, info()->win_ptr);
		info()->win_ptr = NULL;
	}
	if (info()->mlx_ptr)
	{
		mlx_destroy_display(info()->mlx_ptr);
		info()->mlx_ptr = NULL;
	}
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_released(int keycode)
{
	//mlx_clear_window(info()->mlx_ptr, info()->win_ptr);
	if (DEBUG)
		printf("Key pressed:\t(%d)\t(%c)\n", keycode, keycode);
	if (keycode == XK_Escape)
		safe_quit();
	else if (keycode == XK_Up || keycode == XK_w || keycode == XK_KP_Up)
	{
		puts("> Up");
		info()->im_min -= 0.1f;
		info()->im_max -= 0.1f;
		draw();
	}
	else if (keycode == XK_Down || keycode == XK_s || keycode == XK_KP_Down)
	{
		puts("> Down");
		info()->im_min += 0.1f;
		info()->im_max += 0.1f;
		draw();
	}
	else if (keycode == XK_Left || keycode == XK_a || keycode == XK_KP_Left)
	{
		puts("> Left");
		info()->re_min += 0.1f;
		info()->re_max += 0.1f;
		draw();
	}
	else if (keycode == XK_Right || keycode == XK_d || keycode == XK_KP_Right)
	{
		puts("> Right");
		info()->re_min -= 0.1f;
		info()->re_max -= 0.1f;
		draw();
	}
	else if (keycode == XK_minus || keycode == XK_KP_Subtract)
		puts("> -");
	else if (keycode == XK_plus || keycode == XK_KP_Add)
	{
		puts("> +");
		info()->re_min /= 3.0f;
		info()->re_max /= 3.0f;
		info()->im_min /= 3.0f;
		info()->im_max /= 3.0f;
		info()->x_ratio = (info()->re_max - info()->re_min) / (double)WIDTH;
		info()->y_ratio = (info()->im_max - info()->im_min) / (double)HEIGHT;
		draw();
	}
	else if (keycode == XK_1 || keycode == XK_KP_End)
		puts("> Mandelbrot");
	else if (keycode == XK_r) // reset
	{
		;
	}
	return (0);
}

void	fractal_mandelbrot(void)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;
	t_complex	z;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z = (t_complex){0.0f, 0.0f};
			c.re = info()->re_min + (x * info()->x_ratio);
			c.im = info()->im_max - (y * info()->y_ratio);
			i = 0;
			while (z.re < 2 && z.im < 2 && ++i < MAX_ITERATIONS)
			{
				if (z.re * z.re + z.im * z.im >= 4)
					break ;
				z = complex_add(complex_pow2(z), c);
			}
			set_color(x, y, i);
		}
	}
}

void set_color(int x, int y, int i)
{
	int			color;
	double		t;

	if (x == WIDTH / 2 || y == HEIGHT / 2)
		fast_mlx_pixel_put(x, y, 0x00FF0000);
	else
	{
		t = (double)i / MAX_ITERATIONS;
		color = color_bernstein_polynomials1(t);
		fast_mlx_pixel_put(x, y, color);
	}
}

void	draw()
{
	fractal_mandelbrot();
	mlx_put_image_to_window(info()->mlx_ptr, info()->win_ptr,
		info()->img_ptr, 0, 0);
	//fast_mlx_pixel_put(WIDTH / 2, HEIGHT / 2, 0x00FF0000);

}





int	main(void)
{
	/*
	info()->mlx_ptr = mlx_init();
	info()->win_ptr = mlx_new_window(info()->mlx_ptr, WIDTH, HEIGHT, "title");
	info()->img_ptr = mlx_new_image(info()->mlx_ptr, WIDTH, HEIGHT);
	*/

	initialize_variables();
	draw();
	/* Hooks */
	mlx_hook(info()->win_ptr, KeyRelease, KeyReleaseMask, key_released, NULL);
	mlx_hook(info()->win_ptr, ButtonPress, ButtonPressMask, mouse_button_pressed, NULL);
	mlx_hook(info()->win_ptr, DestroyNotify, StructureNotifyMask, safe_quit, NULL);

	/* End Hooks */
	mlx_loop(info()->mlx_ptr);
	return (0);
}
