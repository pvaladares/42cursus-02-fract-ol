/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:33:26 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 23:35:34 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

/*
 Function that will run when the red X window button is pressed
*/
int	hook_action_x_window_pressed(t_app *app)
{
	(void)app;
	exit(EXIT_SUCCESS);
}

/*
 Function displays a string whenever enters the area of the window
*/
int	hook_action_enter_window(int button, int x, int y, t_app *app)
{
	(void)button;
	(void)x;
	(void)y;
	(void)app;
	return (printf("Hello!\n"));
}

/*
 Function displays a string whenever leaves the area of the window
*/
int	hook_action_leave_window(int button, int x, int y, t_app *app)
{
	(void)button;
	(void)x;
	(void)y;
	(void)app;
	return (printf("Bye!\n"));
}
