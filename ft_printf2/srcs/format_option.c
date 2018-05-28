/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:10:20 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/28 18:00:56 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_width(t_var *var)
{
	int i;

	i = 0;
	var->check.len = ft_numlen(var);
	if (var->check.width > 0 && (!(var->check.flags & 1)))
	{
		if (var->check.nb == 0 && ((!(var->check.precwidth))
					|| var->check.precwidth == 0))
		{
			while (i++ < var->check.width)
				ft_buffer(var, ' ');
			return ;
		}
		if (var->check.nb < 0 || var->check.flags & 2 || var->check.flags & 4)
			i++;
		if (var->check.prec & 1 && var->check.precwidth > 0)
			while (i++ < var->check.width - var->check.precwidth)
				ft_buffer(var, ' ');
		if (var->check.precwidth == 0 && (!(var->check.flags & 16)))
			while (i++ < var->check.width - var->check.len)
				ft_buffer(var, ' ');
	}
}

void	ft_process_prec(t_var *var)
{
	int i;

	i = 0;
	if (var->check.prec & 1)
	{
		if (var->check.nb < 0)
			ft_buffer(var, '-');
		if (var->check.flags & 2)
			ft_buffer(var, '+');
		if (var->check.flags & 4)
			ft_buffer(var, ' ');
		while (i++ < var->check.precwidth - var->check.len)
			ft_buffer(var, '0');
	}
}

void	ft_process_flags(t_var *var)
{
	int i;

	i = 0;
	ft_process_width(var);
	ft_process_prec(var);
	if (var->check.flags & 2 && var->check.prec == 0)
	{
		if (var->check.nb >= 0)
		{
			ft_buffer(var, '+');
			i++;
		}
	}
	else if (var->check.flags & 4 && var->check.prec == 0)
		if (var->check.nb >= 0)
		{
			ft_buffer(var, ' ');
			i++;
		}
	if (var->check.flags & 16 && (!(var->check.flags & 1)) &&
			var->check.prec == 0)
	{
		if (var->check.nb < 0)
			i++;
		while (i++ < var->check.width - var->check.len)
			ft_buffer(var, '0');
	}
}

void	ft_process_minus(t_var *var, int neg)
{
	int i;

	i = 0;
	if (var->check.flags & 1)
	{
		if (neg == 1 || var->check.flags & 2 || var->check.flags & 4)
			i++;
		if (var->check.precwidth > 0 && var->check.prec & 1)
			while (i++ < var->check.width - (var->check.len +
						(var->check.precwidth - var->check.len)))
				ft_buffer(var, ' ');
		else
			while (i++ < var->check.width - var->check.len)
				ft_buffer(var, ' ');
	}
}
