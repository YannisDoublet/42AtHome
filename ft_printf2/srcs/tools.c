/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:31:54 by yadouble          #+#    #+#             */
/*   Updated: 2018/06/06 19:04:02 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_len(t_var *var)
{
	if (var->check.type == 'd' || var->check.type == 'D' || 
		var->check.type == 'i')
		ft_numlen(var);
	if (var->check.type == 'x' || var->check.type == 'X' ||
		var->check.type == 'p' || var->check.type == 'P')
		ft_hxlen(var);
	if (var->check.type == 'u' || var->check.type == 'U')
		ft_unsigned_len(var);
	if (var->check.type == 'o' || var->check.type == 'O')
		ft_octlen(var);
}

void	ft_unsigned_len(t_var *var)
{
	uintmax_t nb;
	uintmax_t save;

	ft_conv_type_uU(var);
	nb = var->check.unb;
	var->check.len = 0;
	save = nb;
	if (save == 0)
	{
		var->check.len++;
		return ;
	}
	while (save)
	{
		save /= 10;
		var->check.len++;
	}
}

void	ft_octlen(t_var *var)
{
	ft_conv_type_oO(var);
	if (var->check.nb == 0)
		var->check.len = 1;
	else
		var->check.len = ft_strlen(ft_uitoa_base(var->check.nb, BASE_8));
}

void	ft_hxlen(t_var *var)
{
	if (var->check.type == 'x' || var->check.type == 'X')
		ft_conv_type_xX(var);
	if (var->check.type == 'p' || var->check.type == 'P')
		var->check.nb = va_arg(var->check.arg, unsigned long);
	if (var->check.nb == 0)
		var->check.len = 1;
	else if (var->check.type == 'x' || var->check.type == 'p')
		var->check.len = ft_strlen(ft_uitoa_base(var->check.nb, MIN_BASE_16));
	else if (var->check.type == 'X' || var->check.type == 'P')
		var->check.len = ft_strlen(ft_uitoa_base(var->check.nb, MAJ_BASE_16));
}


int		ft_numlen(t_var *var)
{
	intmax_t save;
	intmax_t nb;

	ft_which_conv(var);
	nb = var->check.nb;
	var->check.len = 0;
	if (nb < 0)
	{		
		if (var->check.flags != 0 && (!(var->check.prec)))
			ft_buffer(var , '-');
		nb *= -1;
	}
	save = nb;
	if (save == 0)
	{
		var->check.len++;
		return (var->check.len);
	}
	while (save)
	{
		save /= 10;
		var->check.len++;
	}
	return (var->check.len);
}