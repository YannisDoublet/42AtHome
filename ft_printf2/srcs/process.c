/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:48:24 by yadouble          #+#    #+#             */
/*   Updated: 2018/06/06 18:57:02 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process(t_var *var)
{
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
		var->check.type == 'p' || var->check.type == 'P')
	{
		ft_process_width(var);
		ft_process_flags(var);
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