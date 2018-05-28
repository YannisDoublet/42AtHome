/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:19:59 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/28 17:03:55 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_which_conv(t_var *var)
{
	var->check.nb = 0;
	if (var->check.conv & 1)
		var->check.nb = (short int)va_arg(var->check.arg, int);
	else if (var->check.conv & 2)
		var->check.nb = (char)va_arg(var->check.arg, int);
	else if (var->check.conv & 4)
		var->check.nb = va_arg(var->check.arg, long int);
	else if (var->check.conv & 8)
		var->check.nb = va_arg(var->check.arg, long long int);
	else if (var->check.conv & 16)
		var->check.nb = va_arg(var->check.arg, intmax_t);
	else if (var->check.conv & 32)
		var->check.nb = va_arg(var->check.arg, size_t);
	else if (var->check.conv == 0)
		var->check.nb = va_arg(var->check.arg, int);
}

void	ft_process_int(t_var *var)
{
	char 		str[BUFF_SIZE];
	int			i;
	int 		len;
	int			neg;

	i = 0;
	neg = 0;
	len = var->check.len;
	if (var->check.nb == 0 && (var->check.prec && (!(var->check.precwidth))))
		return ;
	if (var->check.nb == 0 && (var->check.prec && var->check.precwidth == 0))
	{
		ft_buffer(var, ' ');
		return ;
	}	
	if (var->check.nb < 0)
	{
		neg++;
		if (var->check.flags == 0 && (!(var->check.prec)))
			ft_buffer(var, '-');
		var->check.nb *= -1;
	}
	ft_bzero(str, BUFF_SIZE);
	while (len--)
	{
		if (var->check.nb < 0)
		{
			str[i] = (var->check.nb % 10) * -1 + '0';
			var->check.nb /= 10;
			i++;
		}
		else if (var->check.nb >= 0)
		{
			str[i] = var->check.nb % 10 + '0';
			var->check.nb /= 10;
			i++;
		}
	}
	while (i > 0)
	{
		i--;
		ft_buffer(var, str[i]);
	}
	ft_process_minus(var, neg);
}