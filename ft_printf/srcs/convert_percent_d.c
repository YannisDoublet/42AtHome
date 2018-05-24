/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:46:08 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/18 19:25:35 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putbuffer_nbr(t_var *var)
{
	int i;
	char *str;

	i = 0;
	str = ft_itoa_base(var, "0123456789");
	while (str[i])
		ft_buffer(var, str[i++]);
	printf("str : %s\n", str);
	return (i);
}

int		ft_convert_d(t_var *var)
{
	var->conv.d = va_arg(var->prtf.arg, int);
	//ft_itoa_base()
	return (0);
}