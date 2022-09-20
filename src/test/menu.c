/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:06:30 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/08 19:03:53 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h>

void	display_text(void)
{
	int	x;
	int	y;
	const int	spacing = 15;
	char		*buff;
	//const int	helper_width = WIDTH + HELPER_SIZE;


	buff = malloc(sizeof(char) * MENU_WIDTH);

	mlx_mouse_get_pos(info()->mlx_ptr, info()->win_ptr, &x, &y);

// clear
	mlx_clear_window(info()->mlx_ptr, info()->win_ptr);

	
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 1, WHITE, " INFORMATIONS");
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 2, WHITE, "  xmin = ");
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH + strlen("  xmin = ") + 50, spacing * 2, WHITE, gcvt(info()->re_min, 5, buff));


	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 3, WHITE, "  xmax = ");
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH + strlen("  ymax = ") + 50, spacing * 3, WHITE, gcvt(info()->re_max, 5, buff));

	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 4, WHITE, "  ymin = ");
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH + strlen("  ymin = ") + 50, spacing * 4, WHITE, gcvt(info()->im_min, 5, buff));

	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 5, WHITE, "  ymax = ");
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH + strlen("  ymax = ") + 50, spacing * 5, WHITE, gcvt(info()->im_max, 5, buff));

	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 8, WHITE, " CONTROLS");
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 9, WHITE, " Current mouse position:");
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 10, WHITE, "  x:");
	buff = ft_itoa(x);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 11, WHITE, buff);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 12, WHITE, "  y:");
	buff = ft_itoa(y);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 13, WHITE, buff);
//
//	
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 14, WHITE, "  Re min:");
	buff = ft_itoa(info()->re_min);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 15, WHITE, buff);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 16, WHITE, "  Re max:");
	buff = ft_itoa(info()->re_max);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 17, WHITE, buff);

	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 18, WHITE, "  Im min:");
	buff = ft_itoa(info()->im_min);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 19, WHITE, buff);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 20, WHITE, "  Im max:");
	buff = ft_itoa(info()->im_max);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 21, WHITE, buff);

	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 22, WHITE, "  Iterations");
	buff = ft_itoa(info()->max_iterations);
	mlx_string_put(info()->mlx_ptr, info()->win_ptr, WIDTH, spacing * 23, WHITE, buff);

// put image back
	mlx_put_image_to_window(info()->mlx_ptr, info()->win_ptr, info()->img_ptr, 0, 0);

	free(buff);
	buff = NULL;
}