/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_option_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:25:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 18:23:28 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_minus(t_var *var, int neg)
{
	int i;

	i = ft_minus_type_option(var, neg);
	if (var->check.flags & 1 && i >= 0)
	{
		if (var->check.precwidth > 0 && var->check.prec & 1 &&
			var->check.type != 'c')
		{
			while (i < var->check.width - (var->check.len +
					(var->check.precwidth - var->check.len)))
			{
				ft_buffer(var, ' ');
				i++;
			}
			if (var->check.type == 's' || var->check.type == 'S' || 
				(var->check.type == 's' && var->check.conv & 4))
			{
				while (i < var->check.width - var->check.len)
				{
					ft_buffer(var, ' ');
					i++;
				}
				return ;
			}
		}
		else
		{
			while (i < var->check.width - var->check.len)
			{
				ft_buffer(var, ' ');
				i++;
			}
		}
	}
}