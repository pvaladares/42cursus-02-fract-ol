/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:13:37 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/06 02:25:59 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*contains information about the mlx pointers and windows*/
t_app	*info(void)
{
	static t_app	info;

	return (&info);
}

int	main(void)
{
	create_mlx();
	initialize_variables();
	draw();
	//display_text();
	/* Hooks */
	hooks();

	/* End Hooks */
	mlx_loop(info()->mlx_ptr);
	return (0);
}
