/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:32:58 by yadouble          #+#    #+#             */
/*   Updated: 2018/04/21 19:02:21 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	n = 0;
	if (!s)
		return (NULL);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (n < len)
		str[n++] = s[start++];
	str[n] = '\0';
	return (str);
}
