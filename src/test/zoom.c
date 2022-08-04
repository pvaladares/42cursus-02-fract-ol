/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:40:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/04 14:24:14 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(void)
{
	info()->re_min /= 3.0f;
	info()->re_max /= 3.0f;
	info()->im_min /= 3.0f;
	info()->im_max /= 3.0f;
	info()->x_ratio = (info()->re_max - info()->re_min) / (double)WIDTH;
	info()->y_ratio = (info()->im_max - info()->im_min) / (double)HEIGHT;
	draw();
	puts("Hello zoom!");
}
