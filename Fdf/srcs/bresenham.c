/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:54:00 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/17 20:22:49 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_bresenham(int x1, int y1, int x2, int y2, t_stc *stc)
{
	int ex = abs(x2 - x1);
	int ey = abs(y2 - y1);
	int dx = 2 * ex;
	int dy = 2 * ey;
	int Dx = ex;
	int Dy = ey;
	int i = 0;
	int Xincr = 1;
	int Yincr = 1;

	if (x1 > x2)
		Xincr = -1;
	if (y1 > y2)
		Yincr = -1;
	mlx_pixel_put_to_image(stc, x1, y1, 0xFFFFFF);
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
			mlx_pixel_put_to_image(stc, x1, y1, 0xFF00FF);

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
			mlx_pixel_put_to_image(stc, x1, y1, 0x00FF00);
		}
	}
}

t_pos	*ft_get_x_positions(t_stc *stc, int x, int y)
{
	t_pos 		*pos;

	if (!(pos = malloc(sizeof(t_pos))))
		return (NULL);
	pos->xinit = stc->map.posx[y][x] - stc->map.tab[y][x].height * stc->map.zoom + stc->map.vrt;
	pos->yinit = stc->map.posy[y][x] - stc->map.tab[y][x].height * stc->map.zoom - stc->map.hzt;
	pos->xfin = stc->map.posx[y][x - 1] - stc->map.tab[y][x - 1].height * stc->map.zoom + stc->map.vrt;
	pos->yfin = stc->map.posy[y][x - 1] - stc->map.tab[y][x - 1].height * stc->map.zoom - stc->map.hzt;
	pos->xinit = (pos->xinit - pos->yinit) / 2;
	pos->yinit = (pos->xinit + pos->yinit) / 2;
	pos->xfin = (pos->xfin - pos->yfin) / 2;
	pos->yfin = (pos->xfin + pos->yfin) / 2;

	return (pos);
}

t_pos	*ft_get_y_positions(t_stc *stc, int x, int y)
{
	t_pos 		*pos;

	if (!(pos = malloc(sizeof(t_pos))))
		return (NULL);
	pos->xinit = stc->map.posx[y][x] - stc->map.tab[y][x].height * stc->map.zoom + stc->map.vrt;
	pos->yinit = stc->map.posy[y][x] - stc->map.tab[y][x].height * stc->map.zoom - stc->map.hzt;
	pos->xfin = stc->map.posx[y - 1][x] - stc->map.tab[y - 1][x].height * stc->map.zoom + stc->map.vrt;
	pos->yfin = stc->map.posy[y - 1][x] - stc->map.tab[y - 1][x].height * stc->map.zoom - stc->map.hzt;
	pos->xinit = (pos->xinit - pos->yinit) / 2;
	pos->yinit = (pos->xinit + pos->yinit) / 2;
	pos->xfin = (pos->xfin - pos->yfin) / 2;
	pos->yfin = (pos->xfin + pos->yfin) / 2;
	return (pos);
}