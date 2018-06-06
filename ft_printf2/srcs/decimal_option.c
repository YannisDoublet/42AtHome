/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:11:39 by yadouble          #+#    #+#             */
/*   Updated: 2018/06/06 19:12:12 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_flags_type_option(t_var *var)
{
	int i;

	i = 0;
	if ((var->check.type == 'o' || var->check.type == 'O') &&
		(var->check.flags & 8 && var->check.nb != 0))
		i++;
	if ((var->check.type == 'x' || var->check.type == 'X') && 
		(var->check.flags & 8 && var->check.nb != 0))
		i = i + 2;
	if (var->check.type == 'd' || var->check.type == 'D' || 
		var->check.type == 'i')
	{
		if (var->check.nb < 0)
			i++;
		if (var->check.flags & 2 && var->check.prec == 0)
			if (var->check.nb >= 0)
			{
				ft_buffer(var, '+');
				i++;
			}
		if (var->check.flags & 4 && !(var->check.flags & 2) && !var->check.prec)
			if (var->check.nb >= 0)
			{
				ft_buffer(var, ' ');
				i++;
			}
	}
	return (i);
}

int		ft_minus_type_option(t_var *var, int neg)
{
	int i;

	i = 0;
	if (var->check.type == 'd' || var->check.type == 'D' || 
		var->check.type == 'i')
		if (neg == 1 || var->check.flags & 2 || var->check.flags & 4)
			i++;
	if (var->check.type == 'x' || var->check.type == 'X')
		if (var->check.flags & 8)
			i = i + 2;
	if (var->check.type == 'p' || var->check.type == 'P')
		i = i + 2;
	if ((var->check.type == 'o' || var->check.type == 'O') && 
		var->check.flags & 8 && !(var->check.flags & 16) && var->check.nb != 0)
		i++;
	return (i);
}

void	ft_prec_type_option(t_var *var)
{
	if (var->check.type == 'd' || var->check.type == 'i' || 
		var->check.type == 'D')
	{
		if (var->check.nb < 0)
			ft_buffer(var, '-');
		if (var->check.flags & 2)
			ft_buffer(var, '+');
		if (var->check.flags & 4 && var->check.nb >= 0)
		{
			ft_buffer(var, ' ');
		}
	}
}

int		ft_width_type_option(t_var *var)
{
	int i;

	i = 0;
	if (var->check.type == 'd' || var->check.type == 'i' || 
		var->check.type == 'D')
		if (var->check.nb < 0 || var->check.flags & 2 || var->check.flags & 4)
			i++;
	if ((var->check.type == 'o' || var->check.type == 'O')
		&& (var->check.flags & 8))
	{
		i++;
		if (var->check.prec & 1 && var->check.precwidth == 0 &&
			var->check.nb != 0)
		{
			while (i++ < var->check.width - var->check.len)
				ft_buffer(var, ' ');
			i = -1;
		}
	}
	if (var->check.type == 'p' || var->check.type == 'P')
		i = i + 2;
	if ((var->check.type == 'x' || var->check.type == 'X') 
		&& (var->check.flags & 8))
	{
		i = i + 2;
		if (var->check.prec & 1 && var->check.precwidth == 0 &&
			var->check.nb != 0)
		{
			while (i++ < var->check.width - var->check.len)
				ft_buffer(var, ' ');
			i = -1;
		}
		else if (var->check.prec & 1 && var->check.precwidth == 0 &&
			var->check.nb == 0)
			i = i - 2;
	}
	if ((var->check.nb == 0 && var->check.unb == 0) && var->check.precwidth == 0)
	{
		while (i++ < var->check.width)
			ft_buffer(var, ' ');
		i = -1;
		return (i);
	}
	return (i);
}