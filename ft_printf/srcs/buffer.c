/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:14:53 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/17 21:55:39 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_buffer(t_var *var, char c)
{
	if (ft_strlen(var->prtf.buff) > BUFF_SIZE)
	{
		write(1, var->prtf.buff, BUFF_SIZE);
		var->prtf.bix = 0;
		ft_bzero(var->prtf.buff, var->prtf.bix);
	}
	var->prtf.buff[var->prtf.bix] = c;
}