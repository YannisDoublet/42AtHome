/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:10:20 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 18:13:17 by yadouble         ###   ########.fr       */
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
		if (var->check.prec & 1 && var->check.precwidth >= 0)
		{
			if ((var->check.type == 'c' || var->check.type == 's' ||
				var->check.type == 'S') && var->check.flags & 16)
				return ;
			while ((i < var->check.width - var->check.precwidth &&
					i < var->check.width - var->check.len)
					|| ((i < var->check.width - var->check.len ||
						i < var->check.width - var->check.precwidth) &&
					var->check.type == 's'))
			{
				ft_buffer(var, ' ');
				i++;
			}
			i = -1;
		}
		ft_process_width_2(var, i);
	}
}

void	ft_process_width_2(t_var *var, int i)
{
	if (i != -1 && !var->check.precwidth && ((!(var->check.flags & 16))
		|| (var->check.prec & 1 && (var->check.type != 'c' ||
		var->check.type != 's'))))
		while (i < var->check.width - var->check.len)
		{
			ft_buffer(var, ' ');
			i++;
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
	int		i;
	char	*str;

	i = ft_flags_type_option(var);
	if (var->check.flags & 8 || var->check.type == 'p' ||
		var->check.type == 'P')
	{
		if (var->check.type == 'o' || var->check.type == 'O')
		{
			str = ft_uitoa_base(var->check.nb, BASE_8);
			str[var->check.len] = '\0';
			if (str[0] != '0' && ((var->check.precwidth <= var->check.len &&
				var->check.nb) || (var->check.prec & 1 && !var->check.precwidth
				&& !var->check.nb)))
				ft_buffer(var, '0');
		}
	}
	ft_process_flags_2(var, i);
}

void	ft_process_flags_2(t_var *var, int i)
{
	if (var->check.flags & 8 || var->check.type == 'p' ||
		var->check.type == 'P')
	{
		if ((var->check.type == 'x' && var->check.nb) ||
			(var->check.type == 'p'))
		{
			ft_buffer(var, '0');
			ft_buffer(var, 'x');
		}
		else if ((var->check.type == 'X' && var->check.nb) ||
				(var->check.type == 'P'))
		{
			ft_buffer(var, '0');
			ft_buffer(var, 'X');
		}
	}
	if (var->check.flags & 16 && (!(var->check.flags & 1)) &&
			!var->check.prec && var->check.type != 'c' && i != -1)
		while (i++ < var->check.width - var->check.len)
			ft_buffer(var, '0');
}
