/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:03:16 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/29 17:18:20 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	mlx_pixel_put_to_image(t_stc *stc, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = stc->mlx.x_size * stc->mlx.y_size * stc->mlx.bpp / 8;
	if (x < 0 || y < 0 || y * stc->mlx.size_line
	+ x * stc->mlx.bpp / 8 > img_size || x >= stc->mlx.size_line /
	(stc->mlx.bpp / 8) || y >= img_size / stc->mlx.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = stc->mlx.bpp / 8;
	stc->mlx.img_addr[y * stc->mlx.size_line + x * bit_pix] = color1;
	stc->mlx.img_addr[y * stc->mlx.size_line + x * bit_pix + 1] = color2;
	stc->mlx.img_addr[y * stc->mlx.size_line + x * bit_pix + 2] = color3;
}

void	ft_init_keycode(t_stc *stc)
{
	stc->key.move_x = 0;
	stc->key.move_y = 0;
	stc->key.zoom = 200;
	stc->key.color_bonus = 0;
	stc->key.x_pos = 0;
	stc->key.y_pos = 0;
}

void	ft_init_mlx(t_stc *stc, char **argv)
{
	stc->mlx.mlx_ptr = mlx_init();
	stc->mlx.x_size = 800;
	stc->mlx.y_size = 800;
	stc->mlx.win_ptr = mlx_new_window(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size, argv[1]);
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp,
	&stc->mlx.size_line, &stc->mlx.endian);
}

int		main(int argc, char **argv)
{
	t_stc	*stc;

	if (argc == 2)
	{
		if (!(stc = malloc(sizeof(t_stc))))
			return (-1);
		ft_init_mlx(stc, argv);
		ft_init_keycode(stc);
		ft_fractal_choice(argv[1], stc);
		mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr,
		stc->mlx.img_ptr, 0, 0);
		mlx_loop(stc->mlx.mlx_ptr);
	}
	else
		ft_printf("Usage : ./fractol [Julia], [Mandelbrot], [Burning ship]\n");
	return (0);
}