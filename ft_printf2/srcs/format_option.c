/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:10:20 by yadouble          #+#    #+#             */
/*   Updated: 2018/06/01 16:24:05 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_width(t_var *var)
{
	int i;

	ft_len(var);
	i = ft_width_type_option(var);
	if (var->check.width > 0 && (!(var->check.flags & 1)) && i != -1)
	{
		if (var->check.prec & 1 && var->check.precwidth > 0)
			while (i < var->check.width - var->check.precwidth && 
					i < var->check.width - var->check.len)
			{
				ft_buffer(var, ' ');
				i++;
			}
		else if (var->check.precwidth == 0 && (!(var->check.flags & 16)))
			while (i < var->check.width - var->check.len)
			{
				ft_buffer(var, ' ');
				i++;
			}
	}
}

void	ft_process_prec(t_var *var)
{
	int i;

	i = 0;
	if (var->check.prec & 1)
	{
		ft_prec_type_option(var);
		while (i++ < var->check.precwidth - var->check.len)
			ft_buffer(var, '0');
	}
}

void	ft_process_flags(t_var *var)
{
	int i;

	i = ft_flags_type_option(var);
	if (var->check.flags & 8 && var->check.nb != 0)
	{
		if (var->check.type == 'x')
		{
			ft_buffer(var, '0');
			ft_buffer(var, 'x');
		}
		else
		{
			ft_buffer(var, '0');
			ft_buffer(var, 'X');
		}
	}
	if (var->check.flags & 16 && (!(var->check.flags & 1)) &&
			var->check.prec == 0 && var->check.width > var->check.len)
		while (i++ < var->check.width - var->check.len)
			ft_buffer(var, '0');
}

void	ft_process_minus(t_var *var, int neg)
{
	int i;

	i = ft_minus_type_option(var, neg);
	if (var->check.flags & 1)
	{
		if (var->check.precwidth > 0 && var->check.prec & 1)
			while (i++ < var->check.width - (var->check.len +
						(var->check.precwidth - var->check.len)))
				ft_buffer(var, ' ');
		else
			while (i++ < var->check.width - var->check.len)
				ft_buffer(var, ' ');
	}
}
