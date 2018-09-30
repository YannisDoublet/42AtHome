/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 14:31:54 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/30 13:37:11 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_redraw(t_stc *stc)
{
	mlx_destroy_image(stc->mlx.mlx_ptr, stc->mlx.img_ptr);
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp,
	&stc->mlx.size_line, &stc->mlx.endian);
	ft_fractal_choice(stc);
	mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr,
	stc->mlx.img_ptr, 0, 0);
}

int		ft_motion_hook(int x, int y, t_stc *stc)
{
	if (x < stc->mlx.x_size && y < stc->mlx.y_size && stc->key.act_mouse == 1)
	{
		stc->par.c_r = (x < stc->mlx.x_size / 2) ? (stc->par.c_r + 0.01) :
		(stc->par.c_r - 0.01);
		stc->par.c_i = (y < stc->mlx.y_size / 2) ? (stc->par.c_i + 0.01) :
		(stc->par.c_i - 0.01);
		ft_redraw(stc);
	}
	return (0);
}

int		ft_mousehook(int button, int x, int y, t_stc *stc)
{
	if (button == LEFT_CLICK || button == MOUSE_UP)
	{
		stc->key.zoom *= 1.1;
		stc->par.x1 = stc->par.x1 + ((double)x - ((double)stc->mlx.x_size / 2))
			/ stc->key.zoom;
		stc->par.y1 = stc->par.y1 + ((double)y - ((double)stc->mlx.y_size / 2))
			/ stc->key.zoom;
	}
	else if (button == RIGHT_CLICK || button == MOUSE_DOWN)
	{
		stc->key.zoom *= 0.9;
		stc->par.x1 = stc->par.x1 + ((double)x - ((double)stc->mlx.x_size / 2))
			/ stc->key.zoom;
		stc->par.y1 = stc->par.y1 + ((double)y - ((double)stc->mlx.y_size / 2))
			/ stc->key.zoom;
	}
	ft_redraw(stc);
	return (0);
}

int		ft_keycode2(int key, t_stc *stc)
{
	if (key == ONE)
		stc->par.color_r += 5;
	if (key == TWO)
		stc->par.color_g += 5;
	if (key == THREE)
		stc->par.color_b += 5;
	if (key == FOUR)
		stc->par.color_r -= 5;
	if (key == FIVE)
		stc->par.color_g -= 5;
	if (key == SIX)
		stc->par.color_b -= 5;
	if (key == M)
		stc->key.act_mouse = 1;
	if (key == X)
		stc->key.act_mouse = 0;
	ft_redraw(stc);
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
	{
		ft_init_keycode(stc);
		ft_fractal_init(stc);
	}
	ft_keycode2(key, stc);
	return (0);
}