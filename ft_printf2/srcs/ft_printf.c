/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 20:46:12 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/24 22:13:26 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_var	var;

	va_start(var.check.arg, format);
	ft_parsing_control(&var, format);
	write(1, var.check.buff, var.check.bix);
	return (0);
}