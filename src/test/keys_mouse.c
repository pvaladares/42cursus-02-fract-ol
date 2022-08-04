/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:02:02 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/04 16:01:49 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_moved(int x, int y)
{
	(void)x;
	(void)y;
	display_text();
	//if (DEBUG)
	//	printf("Cursor moved to coordinates:\t(x = %d, y = %d)\n", x, y);
	return (0);
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
	{
		zoom_in(x, y);
		puts("Zoom in");
	}
		
	else if (button == Button5) // Zoom out
	{
		center(x, y);
		puts("Zoom out");
	}
	if (DEBUG)
		printf("Correct cursor coordinates:\t(x = %d, y = %d)\n", x, y);
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
	{
		puts("> -");
	}
	else if (keycode == XK_plus || keycode == XK_KP_Add)
	{
		puts("> +");
	}
	else if (keycode == XK_1 || keycode == XK_KP_End)
		puts("> Mandelbrot");
	else if (keycode == XK_r) // reset
	{
		;
	}
	else if (keycode == XK_c) // center at the cursor
	{
		;
	}
	else if (keycode == XK_Page_Up || keycode == XK_KP_Page_Up)
	{
		printf("Max iterations = (%d)\n", info()->max_iterations);
		info()->max_iterations *= 2;
		draw();
	}
	else if (keycode == XK_Page_Down || keycode == XK_KP_Page_Down)
	{
		printf("Max iterations = (%d)\n", info()->max_iterations);
		info()->max_iterations /= 2;
		draw();
	}
	return (0);
}
