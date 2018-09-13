/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:54:00 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/13 17:47:57 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_bresenham(double x1, double y1, double x2, double y2, t_mlx *mlx)
{
	double ex = fabs(x2 - x1);
	double ey = fabs(y2 - y1);
	double dx = 2 * ex;
	double dy = 2 * ey;
	double Dx = ex;
	double Dy = ey;
	int i = 0;
	int Xincr = 1;
	int Yincr = 1;

	if (x1 > x2)
		Xincr = -1;
	if (y1 > y2)
		Yincr = -1;
	mlx_pixel_put_to_image(mlx, (int)x1, (int)y1, 0xFFFFFF);
	if (Dx > Dy)
	{
		while (i <= Dx)
		{
			i++;
			x1 += Xincr;
			ex -= dy;
			if (ex < 0)
			{
				y1 += Yincr;
				ex += dx;
			}
			mlx_pixel_put_to_image(mlx, (int)x1, (int)y1, 0xFF00FF);

		}
	}
	else
	{
		while (i <= Dy)
		{
			i++;
			y1 += Yincr;
			ey -= dx;
			if (ey < 0)
			{
				x1 += Xincr;
				ey += dy;
			}
			mlx_pixel_put_to_image(mlx, (int)x1, (int)y1, 0x00FF00);
		}
	}
}

t_pos	*ft_get_x_positions(t_mlx *mlx, t_map *map, int x, int y)
{
	t_pos 		*pos;
	int			pad_x;
	int			pad_y;

	pad_x = (mlx->x_size / 3);
	pad_x *= 0.5;
	pad_y = (mlx->y_size / 3);
	pad_y *= 0.5;
	if (!(pos = malloc(sizeof(t_pos))))
		return (NULL);
	pos->xinit = x * 0.2 * pad_x - (double)map->tab[y][x].height + mlx->x_size + map->hzt;
	pos->yinit = y * 0.2 * pad_y - (double)map->tab[y][x].height + map->vrt;
	pos->xfin = (x + 1) * 0.2 * pad_x - (double)map->tab[y][x + 1].height + mlx->x_size + map->hzt;
	pos->yfin = y * 0.2 * pad_y - (double)map->tab[y][x + 1].height + map->vrt;
	pos->xinit = (pos->xinit - pos->yinit) / sqrt(3);
	pos->yinit = (pos->xinit + pos->yinit) / sqrt(3);
	pos->xfin = (pos->xfin - pos->yfin) / sqrt(3);
	pos->yfin = (pos->xfin + pos->yfin) / sqrt(3);
	return (pos);
}

t_pos	*ft_get_y_positions(t_mlx *mlx, t_map *map, int x, int y)
{
	t_pos 		*pos;
	int			pad_x;
	int			pad_y;

	pad_x = (mlx->x_size / 3);
	pad_x *= 0.5;
	pad_y = (mlx->y_size / 3);
	pad_y *= 0.5;
	if (!(pos = malloc(sizeof(t_pos))))
		return (NULL);
	pos->xinit = x * 0.2 * pad_x - (double)map->tab[y][x].height + mlx->x_size + map->hzt;
	pos->yinit = y * 0.2 * pad_y - (double)map->tab[y][x].height + map->vrt;
	pos->xfin = x * 0.2 * pad_x - (double)map->tab[y + 1][x].height + mlx->x_size + map->hzt;
	pos->yfin = (y + 1) * 0.2 * pad_y - (double)map->tab[y + 1][x].height + map->vrt;
	pos->xinit = (pos->xinit - pos->yinit) / sqrt(3);
	pos->yinit = (pos->xinit + pos->yinit) / sqrt(3);
	pos->xfin = (pos->xfin - pos->yfin) / sqrt(3);
	pos->yfin = (pos->xfin + pos->yfin) / sqrt(3);
	return (pos);
}