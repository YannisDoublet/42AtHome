/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 14:31:54 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/29 23:27:03 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_mousehook(int button, int x, int y, t_stc *stc)
{
	if (x > 0 && x < stc->mlx.x_size && y > 0 && y < stc->mlx.y_size)
	{
		if (button == LEFT_CLICK || button == MOUSE_UP)
		{
			stc->key.zoom *= 1.1;
			stc->par.x1 = stc->par.x1 + ((double)x - ((double)stc->mlx.x_size / 2))
				/ stc->key.zoom;
			stc->par.y1 = stc->par.y1 + ((double)y - ((double)stc->mlx.y_size / 2))
				/ stc->key.zoom;
		}
		if (button == RIGHT_CLICK || button == MOUSE_DOWN)
		{
			stc->key.zoom *= 0.9;
			stc->par.x1 = stc->par.x1 + ((double)x - ((double)stc->mlx.x_size / 2))
				/ stc->key.zoom;
			stc->par.y1 = stc->par.y1 + ((double)y - ((double)stc->mlx.y_size / 2))
				/ stc->key.zoom;
		}
		mlx_destroy_image(stc->mlx.mlx_ptr, stc->mlx.img_ptr);
		stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size,
		stc->mlx.y_size);
		stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp,
		&stc->mlx.size_line, &stc->mlx.endian);
		ft_fractal_choice(stc);
		mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr,
		stc->mlx.img_ptr, 0, 0);
	}
	return (0);
}

int		ft_keycode(int key, t_stc *stc)
{
	if (key == ESC)
		exit(0);
	if (key == W)
		stc->key.move_y += 0.1;
	if (key == S)
		stc->key.move_y -= 0.1;
	if (key == A)
		stc->key.move_x += 0.1;
	if (key == D)
		stc->key.move_x -= 0.1;
	if (key == PLUS)
		stc->par.max_iter += 5;
	if (key == MINUS)
		stc->par.max_iter -= 5;
	if (key == RESET)
		ft_init_keycode(stc);
	if (key == ONE)
		stc->par.color_r += 5;
	if (key == TWO)
		stc->par.color_g += 5;
	if (key == THREE)
		stc->par.color_b += 5;
	mlx_destroy_image(stc->mlx.mlx_ptr, stc->mlx.img_ptr);
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp,
	&stc->mlx.size_line, &stc->mlx.endian);
	ft_fractal_choice(stc);
	mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr,
	stc->mlx.img_ptr, 0, 0);
	return (0);
}