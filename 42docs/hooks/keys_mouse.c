/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:37:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/03 13:31:09 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

/*
 Function prints the current position of the mouse cursor on the terminal
*/
int	cursor_moved(int x, int y, t_app *app)
{
	(void)app;
	printf("Cursor coordinates:\t(x = %d, y = %d)\n", x, y);
	return (0);
}

/*
 Function prints the keycode on the terminal
 Just added the Escape key to easily quit the program
*/
int	key_released(int keycode, t_app *app)
{
	printf("Key pressed:\t(%d)\t(%c)\n", keycode, keycode);
	if (keycode == XK_Escape)
		exit(EXIT_SUCCESS);
	(void)app;
	return (0);
}

/*
 Function converts from radians to degrees using the macro M_PI
 from math.h
*/
static float	radians_to_degrees(float radians)
{
	return (radians * (180.0 / M_PI));
}

/*
 Function that will run when any mouse button is pressed
 
 To be noted that the input parameters are given with (0, 0) 
 as top, left corner
 while the subject asks to compute based on the terminal location
 So it is assumed that the terminal location would have the origin as 
 bottom, left corner (0, HEIGHT)
 The following correction is therefore required before computing the tangent
 [x = 0, y = 0] => [x = 0, y = HEIGHT]

 tangent(angle) = y / x = value
 arc tangent(value) = angle ; angle in radians
 
 The final display will have to compute the degrees equivalent 
 so it is easy to cross-check it is computing well for 0º, 45º and 90º
*/
int	mouse_button_pressed(int button, int x, int y, t_app *app)
{
	float	angle;

	(void)app;
	if (DEBUG)
	{
		puts("== ENTERED MOUSE BUTTON PRESSED ==");
		printf("Pressed mouse button:\t(%d)\t(%d)\n", button, button);
		printf("Original cursor coordinates:\t(x = %d, y = %d)\n", x, y);
	}
	y = HEIGHT - y;
	if (DEBUG)
		printf("Correct cursor coordinates:\t(x = %d, y = %d)\n", x, y);
	angle = atan((float) y / x);
	printf("Angle:\t(%.1f) radians == (%.1f) degrees\n",
		angle, radians_to_degrees(angle));
	return (0);
}
