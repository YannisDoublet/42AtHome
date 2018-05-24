/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:19:59 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/24 22:45:51 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_which_conv(t_var *var)
{
	intmax_t nb;

	nb = va_arg(var->check.arg, intmax_t);
	if (var->check.conv & 16)
		nb = (intmax_t)nb;
	else if (var->check.conv & 8)
		nb = (long long int)nb;
	else if (var->check.conv & 4)
		nb = (long int)nb;
	else if (var->check.conv & 32)
		nb = (size_t)nb;
	else if (var->check.conv & 2)
		nb = (char)nb;
	else if (var->check.conv & 1)
		nb = (short int)nb;
	else if (var->check.conv == 0)
		nb = (int)nb;
	return (nb);
}

void	ft_process_int(t_var *var)
{
	intmax_t nb;
	intmax_t save;
	int 	len;
	char 	str[BUFF_SIZE];
	int		i;

	nb = ft_which_conv(var);
	len = 0;
	i = 0;
	if (nb < 0)
	{
		ft_buffer(var, '-');
		nb *= -1;
	}
	save = nb;
	while (save > 0)
	{
		save /= 10;
		len++;
	}
	ft_bzero(str, BUFF_SIZE);
	while (len--)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_buffer(var, str[i]);
	}
}