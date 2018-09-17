/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:39:27 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/17 17:48:02 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	mlx_pixel_put_to_image(t_stc *stc, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = stc->mlx.x_size * stc->mlx.y_size * stc->mlx.bpp / 8;
	if (x < 0 || y < 0 || y * stc->mlx.size_line + x * stc->mlx.bpp / 8 > img_size || x >= stc->mlx.size_line / (stc->mlx.bpp / 8) || y >= img_size / stc->mlx.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = stc->mlx.bpp / 8;
	stc->mlx.img_addr[y * stc->mlx.size_line + x * bit_pix] = color1;
	stc->mlx.img_addr[y * stc->mlx.size_line + x * bit_pix + 1] = color2;
	stc->mlx.img_addr[y * stc->mlx.size_line + x * bit_pix + 2] = color3;
}

void	ft_draw_horizontal_lines(t_stc *stc, int x, int y)
{
	t_pos 	*pos;

	if (y != 0)
	{
		pos = ft_get_y_positions(stc, x, y);
		ft_bresenham(pos->xinit, pos->yinit, pos->xfin, pos->yfin, stc);
	}
}

void	ft_draw_vertical_lines(t_stc *stc, int x, int y)
{
	t_pos	*pos;

	if (x != 0)
	{
		pos = ft_get_x_positions(stc, x, y);
		ft_bresenham(pos->xinit, pos->yinit, pos->xfin, pos->yfin, stc);
	}
}

int		ft_draw(t_stc *stc)
{
	int		x;
	int		x_ecart;
	int		y;
	int		y_ecart;

	y = 0;
	if (!(stc->map.posx = (int**)ft_memalloc(sizeof(int **) * stc->map.height + 1)))
		return (-1);
	if (!(stc->map.posy = (int**)ft_memalloc(sizeof(int **) * stc->map.height + 1)))
		return (-1);
	stc->map.pad_y = ((stc->mlx.y_size / 3) * 2) / stc->map.height;
	x_ecart = ((stc->mlx.x_size / 3) * 2);
	y_ecart = ((stc->mlx.y_size / 3) * 2);
	while (y < stc->map.height)
	{
		x = 0;
		if (!(stc->map.posx[y] = (int*)ft_memalloc(sizeof(int) * stc->map.width[y])))
			return (-1);
		if (!(stc->map.posy[y] = (int*)ft_memalloc(sizeof(int) * stc->map.width[y])))
			return (-1);
		stc->map.pad_x = ((stc->mlx.x_size / 3) * 2) / stc->map.width[y];
		while (x < stc->map.width[y])
		{
				stc->map.posx[y][x] = x * stc->map.pad_x + x_ecart;
				stc->map.posy[y][x] = y * stc->map.pad_y + y_ecart;
				ft_draw_vertical_lines(stc, x, y);
				ft_draw_horizontal_lines(stc, x, y);
				x++;
		}
		y++;
	}
	return (0);
}