/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:14:53 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/25 17:30:17 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_buffer(t_var *var, char c)
{
	if (!var->check.buff[0])
		ft_bzero(var->check.buff, BUFF_SIZE);
	if (ft_strlen(var->check.buff) > BUFF_SIZE)
	{
		write(1, var->check.buff, BUFF_SIZE);
		var->check.bix = 0;
		ft_bzero(var->check.buff, var->check.bix);
	}
	var->check.buff[var->check.bix] = c;
	var->check.bix++;
}