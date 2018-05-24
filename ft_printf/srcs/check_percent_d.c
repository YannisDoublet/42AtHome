/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_percent_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:46:12 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/18 19:28:56 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_minus_flags(const char *str, t_var *var)
{
	int i;
	int	n;

	i = 0;
	n = 0;
	if (var->prtf.flags & 1)
	{
		if ((ft_strlen(ft_itoa_base(var, "0123456789")) <= var->prtf.width ||
			!var->prtf.width))
			return ;
		n = ft_strlen(ft_itoa_base(var, "0123456789"));
		printf("n : %d\n", n);
		while (i + n < var->prtf.width)
		{
			ft_buffer(var, ' ');
			i++;
		}
	}
}

void	ft_flags(const char *str, t_var *var)
{
	ft_minus_flags(str, var);
	if (var->prtf.flags & 2 && ((var->prtf.type == 'd') || 
		(var->prtf.type == 'i') || (var->prtf.type == 'o') || 
		(var->prtf.type == 'u')))
	{
		if ((var->conv.d < 0) || (var->conv.i < 0))
			return ;
		else
			ft_buffer(var, '+');
	}
	ft_putbuffer_nbr(var);
}