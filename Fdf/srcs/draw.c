/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:39:27 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/11 18:26:23 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_horizontal_lines(t_mlx mlx, t_map *map, int x, int y)
{
	t_pos *pos;

	pos = ft_get_y_positions(mlx, map, x, y);
	ft_bresenham(pos->xinit, pos->yinit, pos->xfin, pos->yfin, mlx);
}

void	ft_draw_vertical_lines(t_mlx mlx, t_map *map, int x, int y)
{
	t_pos	*pos;

	pos = ft_get_x_positions(mlx, map, x, y);
	ft_bresenham(pos->xinit, pos->yinit, pos->xfin, pos->yfin, mlx);
}

int		ft_draw(t_mlx mlx, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width[y])
		{
			if (x != map->width[y] - 1)
				ft_draw_vertical_lines(mlx, map, x, y);
			if (y != map->height - 1)
				ft_draw_horizontal_lines(mlx, map, x, y);
			x++;
		}
		y++;
	}
	return (0);
}