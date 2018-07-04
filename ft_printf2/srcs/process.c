/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:48:24 by yadouble          #+#    #+#             */
/*   Updated: 2018/06/19 16:14:56 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process(t_var *var)
{
	if (var->check.a == -1)
		return ;
	if (var->check.type == 'd' || var->check.type == 'i' || 
		var->check.type == 'D')
	{
		ft_process_width(var);
		ft_process_prec(var);
		ft_process_flags(var);
		ft_process_int(var);
	}
	if (var->check.type == 'u' || var->check.type == 'U' ||
		var->check.type == 'o' || var->check.type == 'O' ||
		var->check.type == 'x' || var->check.type == 'X' ||
		var->check.type == 'p' || var->check.type == 'P' ||
		var->check.type == 'c' || var->check.type == 'C' ||
		var->check.type == 's' || var->check.type == 'S')
	{
		ft_process_width(var);
		ft_process_flags(var);
		if (var->check.type == 'c' || var->check.type == 'C' ||
			(var->check.type == 'c' && var->check.conv & 4))
		{
			ft_process_large_char(var);
			return ;
		}
		if (var->check.type == 's' || var->check.type == 'S' || 
			(var->check.type == 's' && var->check.conv & 4))
		{
			ft_process_strings(var);
			return ;
		}
		ft_process_prec(var);
		if (var->check.type == 'u' || var->check.type == 'U')
			ft_process_unsigned(var);
		if (var->check.type == 'o' || var->check.type == 'O')
			ft_process_octal(var);
		if (var->check.type == 'x' || var->check.type == 'X' ||
			var->check.type == 'p' || var->check.type == 'P')
			ft_process_hexadecimal(var);
	}
}

int		ft_surrogates(t_var *var)
{
	if ((var->check.c >= 55296 && var->check.c <= 57343) ||
		(var->check.c == 528384))
		return (-1);
	return (0);
}