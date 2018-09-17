/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:14:30 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/17 19:58:15 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_mlx_init(t_stc *stc)
{
	int 	i;
	int		j;
	
	i = 0;
	j = 0;
	stc->mlx.mlx_ptr = mlx_init();
	stc->mlx.x_size = 1200;
	stc->mlx.y_size = 1200;
	stc->mlx.win_ptr = mlx_new_window(stc->mlx.mlx_ptr, stc->mlx.x_size, stc->mlx.y_size, "FDF");
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size, stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp, &stc->mlx.size_line, &stc->mlx.endian);
}

int		ft_keycode(int key, t_stc *stc)
{
	ft_printf("%d\n", key);
	if (key == ESC)
		exit(1);
	if (key == W)
	{
		stc->map.vrt -= 10;
		stc->map.hzt += 10;
	}
	if (key == S)
	{
		stc->map.hzt -= 10;
		stc->map.vrt += 10;
	}
	if (key == A)
	{
		stc->map.vrt -= 10;
		stc->map.hzt -= 10;
	}
	if (key == D)
	{
		stc->map.vrt += 10;
		stc->map.hzt += 10;
	}
	if (key == PLUS)
		stc->map.zoom += 1;
	if (key == MINUS)
		stc->map.zoom -= 1;
	mlx_destroy_image(stc->mlx.mlx_ptr, stc->mlx.img_ptr);
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size, stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp, &stc->mlx.size_line, &stc->mlx.endian);
	ft_draw(stc);
	mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr, stc->mlx.img_ptr, 0, 0);
	return (0);
}

void	ft_init_keycode(t_stc *stc)
{
	stc->map.hzt = stc->mlx.y_size / 2;
	stc->map.vrt = stc->mlx.x_size / 2;
	stc->map.zoom = 1;
	mlx_key_hook(stc->mlx.win_ptr, ft_keycode, stc);
}
