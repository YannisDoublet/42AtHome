/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 15:48:44 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/29 19:54:58 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_mandelbrot(t_stc *stc)
{
  while(stc->par.y < stc->mlx.y_size)
  {
  	while(stc->par.x < stc->mlx.x_size)
  	{
		stc->par.c_r = stc->par.x / stc->key.zoom + stc->par.x1
		+ stc->key.move_x;
		stc->par.c_i = stc->par.y / stc->key.zoom + stc->par.y1
		+ stc->key.move_y;
		stc->par.z_r = 0;
		stc->par.z_i = 0;
    	while(stc->par.z_r * stc->par.z_r + stc->par.z_i * stc->par.z_i < 4
		&& stc->par.i < stc->par.max_iter)
    	{
			stc->par.tmp = stc->par.z_r;
            stc->par.z_r = stc->par.z_r * stc->par.z_r - stc->par.z_i
			* stc->par.z_i + stc->par.c_r;
            stc->par.z_i = 2 * stc->par.z_i * stc->par.tmp + stc->par.c_i;
			mlx_pixel_put_to_image(stc, stc->par.x, stc->par.y,
			stc->par.i * 510);
		  	stc->par.i++;
    	}
		if (stc->par.i == stc->par.max_iter)
			mlx_pixel_put_to_image(stc, stc->par.x, stc->par.y, 0xFFFFFF);
		stc->par.x++;
		stc->par.i = 0;
 	 }
	stc->par.x = 0;
	stc->par.y++;
  }
  return (0);
}
