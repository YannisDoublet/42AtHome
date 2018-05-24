/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:28:43 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/18 18:31:27 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_format(t_var *var)
{
	if (var->prtf.type == 'd' || var->prtf.type == 'i')
		ft_convert_d(var);
	
}