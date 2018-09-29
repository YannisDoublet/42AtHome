/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:30:01 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/29 18:55:52 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_fractal_choice(char *str, t_stc *stc)
{
	mlx_hook(stc->mlx.win_ptr, 2, 2, ft_keycode, stc);
	mlx_mouse_hook(stc->mlx.win_ptr, ft_mousehook, stc);
	if (ft_strcmp(str, "Julia") == 0)
	{
		ft_init_julia_param(stc);
		ft_julia(stc);
	}
	else if (ft_strcmp(str, "Mandelbrot") == 0)
	{
		ft_init_mandelbrot_param(stc);
		ft_mandelbrot(stc);
	}
	/*else if (ft_strcmp(str, "Burning Ship"))
		ft_burning_ship(stc);*/
}