/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 21:03:37 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/28 10:18:58 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_parsing_center(const char *fmt, t_var *var)
{

	ft_parse_flags(fmt, var);
	ft_parse_width(fmt, var);
	ft_parse_precision(fmt, var);
	ft_parse_conv(fmt, var);
	ft_parse_type(fmt, var);
	return (0);
}

int		ft_parsing_control(t_var *var, const char *fmt)
{
	var->check.i = 0;
	var->check.bix = 0;
	while (fmt[var->check.i])
	{
		var->check.flags = 0;
		var->check.conv = 0;
		var->check.width = 0;
		var->check.prec = 0;
		var->check.precwidth = 0;
		if (fmt[var->check.i] == '%')
		{
			var->check.i++;
			if (fmt[var->check.i] == '%')
			{
				ft_buffer(var, fmt[var->check.i]);
				var->check.i++;
			}
			else
			{
				ft_parsing_center(fmt, var);
				ft_process(var);
			}
		}
		else
		{
			ft_buffer(var, fmt[var->check.i]);
			var->check.i++;
		}
	}
	return (0);
}