/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:54:00 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/11 21:16:23 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_bresenham(double x1, double y1, double x2, double y2, t_mlx mlx)
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
	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, (int)x1, (int)y1, 0xFF00FF);	
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
			printf("1er x1 : %f, 1er y1 : %f\n", x1, y1);
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, (int)x1, (int)y1, 0xFF00FF);

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
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, (int)x1, (int)y1, 0x00FF00);

		}
	}
}

t_pos	*ft_get_x_positions(t_mlx mlx, t_map *map, int x, int y)
{
	t_pos 		*pos;

	if (!(pos = malloc(sizeof(t_pos))))
		return (NULL);
	pos->xinit = x * 0.2 * ((double)mlx.x_size / 8) + (double)map->tab[y][x].height + ((double)mlx.x_size / 3);
	pos->xinit = round((sqrt(3) / 2) * pos->xinit);
	printf("x :%f\n", pos->xinit);
	pos->yinit = y * 0.2 * ((double)mlx.y_size / 8) + (double)map->tab[y][x].height + ((double)mlx.x_size / 3);
	pos->yinit = round(pos->yinit * -0.5 + (mlx.y_size / 2));
	printf("x : %f\n", pos->yinit);
	pos->xfin = (x + 1) * 0.2 * ((double)mlx.x_size / 8) + (double)map->tab[y][x + 1].height + ((double)mlx.x_size / 3);
	pos->xfin = round((sqrt(3) / 2) * pos->xfin);
	printf("x : %f\n", pos->xfin);
	pos->yfin = y * 0.2 * ((double)mlx.y_size / 8) + (double)map->tab[y][x + 1].height + ((double)mlx.x_size / 3);
	pos->yfin = round(pos->yfin * 0.5 + (mlx.y_size / 2));
	printf("x : %f\n", pos->yfin);
	return (pos);
}

t_pos	*ft_get_y_positions(t_mlx mlx, t_map *map, int x, int y)
{
	t_pos 		*pos;

	if (!(pos = malloc(sizeof(t_pos))))
		return (NULL);
	pos->xinit = x * 0.2 * ((double)mlx.x_size / 8) + (double)map->tab[y][x].height + ((double)mlx.x_size / 3);
	pos->xinit = round((sqrt(3) / 2) * pos->xinit);
	printf("y : %f\n", pos->xinit);
	pos->yinit = y * 0.2 * ((double)mlx.y_size / 8) + (double)map->tab[y][x].height + ((double)mlx.x_size / 3);
	pos->yinit = round(pos->yinit * -0.5 + (mlx.y_size / 2));
	printf("y : %f\n", pos->yinit);
	pos->xfin = x * 0.2 * ((double)mlx.x_size / 8) + (double)map->tab[y + 1][x].height + ((double)mlx.x_size / 3);
	pos->xfin = round((sqrt(3) / 2) * pos->xfin);
	printf("y : %f\n", pos->xfin);
	pos->yfin = (y + 1) * 0.2 * ((double)mlx.y_size / 8) + (double)map->tab[y + 1][x].height + ((double)mlx.x_size / 3);
	pos->yfin = round(pos->yfin * 0.5 + (mlx.y_size / 2));
	printf("y : %f\n", pos->yfin);
	return (pos);
}