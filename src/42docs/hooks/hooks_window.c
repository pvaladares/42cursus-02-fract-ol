/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:33:26 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 12:52:01 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

/*
 Function displays a string whenever enters the area of the window
*/
int	hook_action_mouse_moved(int button, int x, int y, t_app *app)
{
	(void)button;
	(void)app;
	printf("Mouse moved: (x = %d, y = %d)\n", x, y);
	return (0);
}
