/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 18:56:06 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/29 19:56:58 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_init_mandelbrot_param(t_stc *stc)
{
	stc->par.x1 = -2.1;
	stc->par.x2 = 0.6;
	stc->par.y1 = -1.2;
	stc->par.y2 = 1.2;
	stc->par.i = 0;
	stc->par.x = 0;
	stc->par.y = 0;
	stc->par.max_iter = 50;
}

void	ft_init_julia_param(t_stc *stc)
{
	stc->par.x1 = 0;
	stc->par.x2 = 0;
	stc->par.y1 = 0;
	stc->par.y2 = 0;
	stc->par.i = 0;
	stc->par.x = 0;
	stc->par.y = 0;
	stc->par.max_iter = 0;
}