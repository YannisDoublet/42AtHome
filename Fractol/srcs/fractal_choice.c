/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:30:01 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/30 13:36:25 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_fractal_check(char *str, t_stc *stc)
{
	if (ft_strcmp(str, "Julia") == 0)
	{
		stc->key.fract = 1;
		return (1);
	}
	else if (ft_strcmp(str, "Mandelbrot") == 0)
	{
		stc->key.fract = 2;
		return (1);
	}
	else if (ft_strcmp(str, "Burning_Ship") == 0)
	{
		stc->key.fract = 3;
		return (1);
	}
	return (-1);
}

void	ft_fractal_init(t_stc *stc)
{
	if (stc->key.fract == 1)
		ft_init_julia_param(stc);
	else if (stc->key.fract == 2)
		ft_init_mandelbrot_param(stc);
	else if (stc->key.fract == 3)
		ft_init_burning_ship(stc);
}

void	ft_fractal_choice(t_stc *stc)
{
	mlx_hook(stc->mlx.win_ptr, 2, 2, ft_keycode, stc);
	mlx_hook(stc->mlx.win_ptr, 6, 3, ft_motion_hook, stc);
	mlx_mouse_hook(stc->mlx.win_ptr, ft_mousehook, stc);
	if (stc->key.fract == 1)
		ft_julia(stc);
	else if (stc->key.fract == 2)
		ft_mandelbrot(stc);
	else if (stc->key.fract == 3)
		ft_burning_ship(stc);
}