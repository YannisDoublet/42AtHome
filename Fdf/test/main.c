/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:50:00 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/20 19:21:27 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_pixel(int button, t_test *mlx)
{
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, mlx->y, 0xFFFFFFF);
	return (0);
}

int		ft_put_pixel(int key, t_test *mlx)
{
	printf("key : %d\n", key);
	if (key == 123)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x - 1), mlx->y, 0x0000FF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x - 2), mlx->y, 0x0000FF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x - 3), mlx->y, 0x0000FF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x - 4), mlx->y, 0x0000FF);
		mlx->x -= 4;
	}
	else if (key == 124)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x + 1), mlx->y, 0x00FF00);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x + 2), mlx->y, 0x00FF00);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x + 3), mlx->y, 0x00FF00);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x + 4), mlx->y, 0x00FF00);
		mlx->x += 4;
	}
	else if (key == 125)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y + 1), 0xFF0000);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y + 2), 0xFF0000);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y + 3), 0xFF0000);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y + 4), 0xFF0000);
		mlx->y += 4;
	}
	else if (key == 126)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y - 1), 0xFFFFFF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y - 2), 0xFFFFFF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y - 3), 0xFFFFFF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y - 4), 0xFFFFFF);
		mlx->y -= 4;
	}
	return (0);
}

int		main(void)
{
	t_test	*mlx;

	mlx->x = 10;
	mlx->y = 10;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 500, 500, "Yo c les test mdrr");
	mlx_key_hook(mlx->win_ptr, ft_put_pixel, mlx);
	mlx_mouse_hook(mlx->win_ptr, ft_pixel, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}