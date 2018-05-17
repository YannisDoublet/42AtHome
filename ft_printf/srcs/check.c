/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:31:51 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/17 21:49:11 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*void	ft_minus_flags(const char *str, t_var *var)
{
	if (var->prtf.flags & 1)
	{
		if (var->prtf.)
	}
}*/

void	ft_flags(const char *str, t_var *var)
{
	if (var->prtf.flags & 2 && ((var->prtf.type == 'd') || 
		(var->prtf.type == 'i') || (var->prtf.type == 'o') || 
		(var->prtf.type == 'u')))
	{
		if (var->conv.d < 0)
			return ;
		else
			ft_buffer(var, '+');
		printf("%s\n", var->prtf.buff);
	}
}