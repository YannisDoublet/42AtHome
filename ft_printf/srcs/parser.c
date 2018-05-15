/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:49:42 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/15 21:56:59 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_is_flag_valid(const char *str, t_var *var)
{
	var->prtf.i++;
	var->flag.valide_flag = 1;
}

void		ft_is_width_valid(const char *str, t_var *var)
{
	
}

void		ft_is_precision_valid(const char *str, t_var *var)
{
	
}

void		ft_is_size_valid(const char *str, t_var *var)
{
	
}

void		ft_is_type_valid(const char *str, t_var *var)
{
	
}

int		ft_parser(const char *str, t_var *var)
{
	var->prtf.i = 0;
	while (str[var->prtf.i])
		if (str[var->prtf.i] == '%')
		{
			var->prtf.i++;
			if ((var->prtf.i = (ft_is_flag_valid(str, var) == 0)))
				ft_flags(t_var *var);
			if((var->prtf.i = !ft_is_width_valid(str, var)))
			if ((var->prtf.i = !ft_is_precision_valid(str, var)))
			if ((var->prtf.i = !ft_is_size_valid(str, var)))
			if ((var->prtf.i = !ft_is_type_valid(str, var)))
		}
		var->prtf.i++;
	return (1);
}