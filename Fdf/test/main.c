/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:50:00 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/20 16:21:41 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_put_pixel(int key, t_test mlx)
{
	if (key == 123)
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, (mlx.x - 1), mlx.y, 0xFFFFFF);
	else if (key == 124)
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, mlx.x, (mlx.y + 1), 0xFFFFFF);
	else if (key == 125)
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, mlx.x, (mlx.y + 1), 0xFFFFFF);
	else if (key == 126)
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, (mlx.x + 1), mlx.y, 0xFFFFFF);
	return (0);
}

int		main(void)
{
	t_test	mlx;
	
	mlx.x = 10;
	mlx.y = 10;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1000, 1000, "Yo c les test mdrr");
	mlx_key_hook(mlx.win_ptr, ft_put_pixel, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}