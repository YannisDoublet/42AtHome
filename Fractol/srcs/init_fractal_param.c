/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 18:56:06 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/29 23:21:50 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_init_burning_ship(t_stc *stc)
{
	stc->par.x1 = -2;
	stc->par.x2 = 1;
	stc->par.y1 = -2;
	stc->par.y2 = 1.2;
	stc->par.max_iter = 50;
		stc->par.color_r = 25;
	stc->par.color_g = 10;
}

void	ft_init_mandelbrot_param(t_stc *stc)
{
	stc->par.x1 = -2.1;
	stc->par.x2 = 0.6;
	stc->par.y1 = -1.2;
	stc->par.y2 = 1.2;
	stc->par.max_iter = 50;
	stc->par.color_r = 15;
	stc->par.color_g = 20;
}

void	ft_init_julia_param(t_stc *stc)
{
	stc->par.x1 = -1;
	stc->par.x2 = 1;
	stc->par.y1 = -1.2;
	stc->par.y2 = 1.2;
	stc->par.max_iter = 150;
	stc->par.color_r = 30;
	stc->par.color_g = 15;
}
