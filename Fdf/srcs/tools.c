/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:14:30 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/13 17:44:56 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_mlx_init(t_mlx *mlx)
{
	int 	i;
	int		j;
	
	i = 0;
	j = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->x_size = 1200;
	mlx->y_size = 1200;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->x_size, mlx->y_size, "FDF");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->x_size, mlx->y_size);
	mlx->img_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
}

int		ft_keycode(int key, t_map *map, t_mlx *mlx)
{
	if (key == 13)
		map->vrt += 10;
	else if (key == 0)
		map->hzt -= 10;
	else if (key == 1)
		map->vrt -= 10;
	else if (key == 2)
		map->vrt += 10;
	ft_bzero(mlx->img_addr, (mlx->x_size * mlx->y_size * 4));
	return (0);
}

void	ft_init_keycode(t_map *map, t_mlx *mlx)
{
	map->hzt = 0;
	map->vrt = 0;
	map->zoom = 0;
	mlx_key_hook(mlx->win_ptr, ft_keycode, mlx);
}
