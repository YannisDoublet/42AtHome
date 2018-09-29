/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:36:20 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/29 15:45:43 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_julia(t_stc *stc)
{
  double cre;
  double cim; 
  double newre;
  double newim;
  double oldre;
  double oldim;
  int maxiter;
  int i;
  int x;
  int y;

  cre = -0.75;
  cim = -0.14;
  x = 0;
  y = 0;
  i = 0;
  maxiter = 150;

  while(y < stc->mlx.y_size)
  {
  	while(x < stc->mlx.x_size)
  	{
		newre = 1.5 * (x - stc->mlx.x_size / 2) /
		(0.5 * stc->key.zoom * stc->mlx.x_size) + stc->key.move_x;
    	newim = (y - stc->mlx.y_size / 2) /
		(0.5 * stc->key.zoom * stc->mlx.y_size) + stc->key.move_y;
    	while(i < maxiter)
    	{
			oldre = newre;
			oldim = newim;
    	  	newre = oldre * oldre - oldim * oldim + cre;
    	  	newim = 2 * oldre * oldim + cim;
    	  	if((newre * newre + newim * newim) > 4)
		  		break;
			mlx_pixel_put_to_image(stc, x, y, i * 510);
		  	i++;
    	}
		x++;
		i = 0;
 	 }
	x = 0;
	y++;
  }
  return 0;
}