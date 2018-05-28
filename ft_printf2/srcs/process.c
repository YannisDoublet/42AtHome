/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:48:24 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/28 17:02:04 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process(t_var *var)
{
	if (var->check.type == 'd' || var->check.type == 'i')
	{
		ft_process_flags(var);
		ft_process_int(var);
	}
	/*if (var->check.type == 'u' || var->check.type == 'o' 
		|| var->check.type == 'x' || var->check.type == 'X')
	{
		ft_process_flags(var);
		ft_process_unsigned_int(var);
		ft_process_minus(var, ft_process_unsigned_int(var));
	}*/
}