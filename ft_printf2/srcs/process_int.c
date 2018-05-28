/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:19:59 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/28 14:36:34 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_width_and_prec(t_var *var)
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
	if (var->check.prec & 1)
	{
		i = 0;
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
	ft_process_width_and_prec(var);
	if (var->check.flags != 0)
	{
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
}

void	ft_which_conv(t_var *var)
{
	var->check.nb = 0;
	if (var->check.conv & 1)
		var->check.nb = (short int)va_arg(var->check.arg, int);
	else if (var->check.conv & 2)
		var->check.nb = (char)va_arg(var->check.arg, int);
	else if (var->check.conv & 4)
		var->check.nb = va_arg(var->check.arg, long int);
	else if (var->check.conv & 8)
		var->check.nb = va_arg(var->check.arg, long long int);
	else if (var->check.conv & 16)
		var->check.nb = va_arg(var->check.arg, intmax_t);
	else if (var->check.conv & 32)
		var->check.nb = va_arg(var->check.arg, size_t);
	else if (var->check.conv == 0)
		var->check.nb = va_arg(var->check.arg, int);
}

void	ft_process_int(t_var *var)
{
	char 		str[BUFF_SIZE];
	int			i;
	int 		len;
	int			neg;

	i = 0;
	neg = 0;
	len = var->check.len;
	if (var->check.nb == 0 && (var->check.prec && (!(var->check.precwidth))))
		return ;
	if (var->check.nb == 0 && (var->check.prec && var->check.precwidth == 0))
	{
		ft_buffer(var, ' ');
		return ;
	}	
	if (var->check.nb < 0)
	{
		neg++;
		if (var->check.flags == 0 && (!(var->check.prec)))
			ft_buffer(var, '-');
		var->check.nb *= -1;
	}
	ft_bzero(str, BUFF_SIZE);
	while (len--)
	{
		if (var->check.nb < 0)
		{
			str[i] = (var->check.nb % 10) * -1 + '0';
			var->check.nb /= 10;
			i++;
		}
		else
		{
			str[i] = var->check.nb % 10 + '0';
			var->check.nb /= 10;
			i++;
		}
	}
	while (i > 0)
	{
		i--;
		ft_buffer(var, str[i]);
	}
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