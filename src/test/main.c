#include "fractol.h"

/*contains information about the mlx pointers and windows*/
t_app	*info(void)
{
	static t_app	info;

	return (&info);
}

void	fast_mlx_pixel_put(int x, int y, int color)
{
	//x += WIDTH / 2;
	//y += HEIGHT / 2;ãpp
	info()->img_addr[y * WIDTH + x] = color;
}

void	initialize_variables()
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
			info()->img_ptr,
			&info()->bits_per_pixel, &info()->line_length, &info()->endian);

	//info()->img_ptr = info()->img_address;


}

int	fractal_mandelbrot(int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			i;

	// Convert integer x,y coordinates TO double complex Re, Im
	c.re = info()->re_min + (x * info()->x_ratio);
	c.im = info()->im_max - (y * info()->y_ratio);
	z.re = 0.0f;  // z_n+1 = z_n * z_n + c, z_0 = 0
	z.im = 0.0f;
	i = 1; // iteration starts on 1
	while (i <= MAX_ITERATIONS)
	{
		if (complex_norm(c) > 2)
			break; // diverges to inf.
		z = complex_add(complex_pow2(z), c);
		i++;
	}
	//if (i >= MAX_ITERATIONS)
	//	mlx_pixel_put(app->mlx_ptr, app->win_ptr, x, y, 0x00FF0000);
	//fast_mlx_pixel_put(app, x, y, 0x00FF0000);
	return (i);
}

int	mouse_button_pressed(int button, int x, int y)
{
	
	//mlx_clear_window(info()->mlx_ptr, info()->win_ptr);
	//mlx_do_sync(info()->mlx_ptr);
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
	//mlx_string_put(app->mlx_ptr, app->win_ptr, x, y, 0x00FF0000, "Hello");
	//y = HEIGHT - y;
	if (DEBUG)
		printf("Correct cursor coordinates:\t(x = %d, y = %d)\n", x, y);
	//fast_mlx_pixel_put(x, y, 0x00FF0000);
	//mlx_put_image_to_window(info()->mlx_ptr, info()->win_ptr,
//		info()->img_ptr, 0, 0);
	return (0);
}

int	safe_quit()
{
	/*
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
	}*/
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


	}
		
	else if (keycode == XK_1 || keycode == XK_KP_End)
		puts("> Mandelbrot");
	return (0);
}



void	create_mandelbrot()
{
	int	 x, y;
	t_complex c;
	t_complex z;
	int iterations;
	//int color;
	//float t;
	/*
	double im_min = -2.0f;
	double re_factor = (re_max-re_min)/(WIDTH-1);
	double im_factor = (im_max-im_min)/(HEIGHT-1);
	unsigned MaxIterations = 100;
	unsigned int	n;
*/
	//double pixel_size = (info()->re_max - info()->re_min) / WIDTH;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = info()->re_min + (x * info()->x_ratio);
			c.im = info()->im_max - (y * info()->y_ratio);
			z.re = 0.0f;
			z.im = 0.0f;
			iterations = 1;
			while (iterations < MAX_ITERATIONS)
			{
				if (complex_norm(z) > 2)
					break;
				z = complex_add(complex_pow2(z), c);
				iterations++;
			}
			
			if ( DEBUG && (c.re == 0.0f || c.im == 0.0f)) // draw axis after convert from pixels to point
				fast_mlx_pixel_put(x, y, 0x00FF0000);
				/*
			else 
			{ // color using smooth pallete
				//t = (float)n / MAX_ITERATIONS;
				color = 0x00FF0000 + n*n*n;
				fast_mlx_pixel_put(x, y, color);
			}*/
			//if (x == WIDTH / 2 || y == HEIGHT / 2)
			fast_mlx_pixel_put(x, y, 0x000000FF + pow(iterations,5));
		//	else
		//		fast_mlx_pixel_put(x, y, 0x00FF0000);

			x++;
		}
		y++;
		//mlx_string_put()
	}
}


void	draw()
{
	create_mandelbrot();
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
