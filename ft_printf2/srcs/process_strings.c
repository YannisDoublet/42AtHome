/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 20:46:33 by yadouble          #+#    #+#             */
/*   Updated: 2018/06/30 17:02:13 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_wcharlen(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c > 127 && c <= 2047)
		return (2);
	else if (c > 2047 && c <= 65536)
		return (3);
	else if (c > 65536 && c <= 1141111)
		return (4);
	return (-1);
}


int		ft_check_surrogates(t_var *var)
{
	int i;
	int surrogates;

	i = 0;
	surrogates = 0;
	while (var->check.strl[i])
	{
		if (var->check.strl[i] < 0 || 
			(var->check.strl[i] >= 0xD800 && var->check.strl[i] <= 0xDBFF) ||
			(var->check.strl[i] >= 0xDC00 && var->check.strl[i] <= 0xDFFF))
		{
			var->check.bix = -1;
			return (-1);
		}
		i++;
	}
	return (1);
}

void	ft_process_strings(t_var *var)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (((var->check.type == 'S') ||
		(var->check.type == 's' && var->check.conv & 4)) &&
		ft_check_surrogates(var) == -1)
		return ;
	if (var->check.type == 'S' ||
		(var->check.type == 's' && var->check.conv & 4))
	{
		if (var->check.prec & 1)
		{
			if (!var->check.precwidth)
			{
				ft_process_minus(var, 0);
				return ;
			}
			while (var->check.strl[i] && c < var->check.precwidth &&
					c < var->check.len)
			{
				if (ft_get_wcharlen(var->check.strl[i]) == -1)
				{
					var->check.bix = -1;
					return ;
				}
				if ((c + ft_get_wcharlen(var->check.strl[i])) >
					var->check.precwidth)
				{
					var->check.len -= ft_get_wcharlen(var->check.strl[i]);
					ft_process_minus(var, 0);
					return ;
				}
				var->check.c = var->check.strl[i];
				ft_process_large_char(var);
				c += ft_get_wcharlen(var->check.strl[i]);
				i++;
			}
		}
		else
		{
			while (var->check.strl[i])
			{
				var->check.c = var->check.strl[i];
				ft_process_large_char(var);
				i++;
			}
		}
	}
	if (var->check.type == 's' && !var->check.conv)
	{
		if (var->check.prec & 1)
		{
			if (!var->check.precwidth)
			{
				ft_process_minus(var, 0);
				return ;
			}
			while (i < var->check.precwidth && i < var->check.len)
			{
				ft_buffer(var, var->check.str[i]);
				i++;
			}
		}
		else
			while (var->check.str[i])
			{
				ft_buffer(var, var->check.str[i]);
				i++;
			}
	}
	ft_process_minus(var, 0);
}
