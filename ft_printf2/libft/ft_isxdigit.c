/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:42:40 by yadouble          #+#    #+#             */
/*   Updated: 2018/04/22 16:45:04 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isxdigit(int c)
{
	if (((unsigned char)c >= '0' && (unsigned char)c <= '9') || ((unsigned
					char)c >= 'a' && (unsigned char)c <= 'f') || ((unsigned
						char)c >= 'A' && (unsigned char)c <= 'F'))
		return (1);
	return (0);
}
