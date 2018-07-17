/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:19:59 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 15:45:06 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_iscntrl(int c)
{
	if ((unsigned char)c <= 31 || (unsigned char)c == 127)
		return (1);
	return (0);
}
