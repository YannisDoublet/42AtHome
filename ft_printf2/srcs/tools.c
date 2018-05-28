/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:31:54 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/28 17:01:23 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_numlen(t_var *var)
{
	intmax_t save;
	intmax_t nb;

	ft_which_conv(var);
	nb = var->check.nb;
	var->check.len = 0;
	if (nb < 0)
	{
		if (var->check.flags != 0 && (!(var->check.prec)))
			ft_buffer(var , '-');
		nb *= -1;
	}
	save = nb;
	if (save == 0)
	{
		var->check.len++;
		return (var->check.len);
	}
	while (save)
	{
		save /= 10;
		var->check.len++;
	}
	return (var->check.len);
}