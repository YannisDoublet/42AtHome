/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:42:40 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 15:45:31 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isxdigit(int c)
{
	if (((unsigned char)c >= '0' && (unsigned char)c <= '9') || ((unsigned
					char)c >= 'a' && (unsigned char)c <= 'f') || ((unsigned
						char)c >= 'A' && (unsigned char)c <= 'F'))
		return (1);
	return (0);
}
