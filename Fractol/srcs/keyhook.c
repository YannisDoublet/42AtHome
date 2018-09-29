/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 14:31:54 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/29 18:48:14 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_mousehook(int button, int x, int y, t_stc *stc)
{
	(void)x;
	(void)y;
	if (button == MOUSE_UP)
		stc->key.zoom += 20;
	if (button == MOUSE_DOWN)
		stc->key.zoom -= 20;
	mlx_destroy_image(stc->mlx.mlx_ptr, stc->mlx.img_ptr);
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp,
	&stc->mlx.size_line, &stc->mlx.endian);
	ft_fractal_choice("Mandelbrot", stc);
	mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr,
	stc->mlx.img_ptr, 0, 0);
	return (0);
}

int		ft_keycode(int key, t_stc *stc)
{
	if (key == ESC)
		exit(1);
	if (key == W)
		stc->key.move_y += 0.1;
	if (key == S)
		stc->key.move_y -= 0.1;
	if (key == A)
		stc->key.move_x += 0.1;
	if (key == D)
		stc->key.move_x -= 0.1;
	mlx_destroy_image(stc->mlx.mlx_ptr, stc->mlx.img_ptr);
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp,
	&stc->mlx.size_line, &stc->mlx.endian);
	ft_fractal_choice("Mandelbrot", stc);
	mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr,
	stc->mlx.img_ptr, 0, 0);
	return (0);
}