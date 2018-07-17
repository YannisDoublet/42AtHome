/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:56:39 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 15:46:14 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str;

	if (!(str = malloc(sizeof(size_t) * size)))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
