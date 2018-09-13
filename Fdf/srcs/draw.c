/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:39:27 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/13 17:44:26 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	mlx_pixel_put_to_image(t_mlx *mlx, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = mlx->x_size * mlx->y_size * mlx->bpp / 8;
	if (x < 0 || y < 0 || y * mlx->size_line + x * mlx->bpp / 8 > img_size || x >= mlx->size_line / (mlx->bpp / 8) || y >= img_size / mlx->size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = mlx->bpp / 8;
	mlx->img_addr[y * mlx->size_line + x * bit_pix] = color1;
	mlx->img_addr[y * mlx->size_line + x * bit_pix + 1] = color2;
	mlx->img_addr[y * mlx->size_line + x * bit_pix + 2] = color3;
}

void	ft_draw_horizontal_lines(t_mlx *mlx, t_map *map, int x, int y)
{
	t_pos 	*pos;

	pos = ft_get_y_positions(mlx, map, x, y);
	ft_bresenham(pos->xinit, pos->yinit, pos->xfin, pos->yfin, mlx);
}

void	ft_draw_vertical_lines(t_mlx *mlx, t_map *map, int x, int y)
{
	t_pos	*pos;

	pos = ft_get_x_positions(mlx, map, x, y);
	ft_bresenham(pos->xinit, pos->yinit, pos->xfin, pos->yfin, mlx);
}

int		ft_draw(t_mlx *mlx, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	ft_init_keycode(map, mlx);
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