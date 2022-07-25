/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:14:11 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/24 00:02:14 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	//printf("Pressed key %d %c\n", keycode, keycode);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		perror("Error with mlx_init()");
		exit(EXIT_FAILURE);
	}	
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	if (!vars.win)
	{
		perror("Error with mlx_new_window()");
		//free(vars.mlx);
		exit(EXIT_FAILURE);
	}	
	mlx_hook(vars.win, KeyPress, KeyPressMask, close, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}

// https://en.wikipedia.org/wiki/Mandelbrot_set

