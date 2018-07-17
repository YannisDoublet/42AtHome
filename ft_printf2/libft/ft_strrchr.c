/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:01:45 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 15:49:31 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			tmp = (char*)s + i;
		i++;
	}
	if ((char)c == '\0')
		return ((char*)s + i);
	return (tmp);
}
