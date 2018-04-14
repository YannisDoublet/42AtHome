/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannisdo <yannisdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:55:23 by yannisdo          #+#    #+#             */
/*   Updated: 2018/04/13 14:55:26 by yannisdoublet    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(char *s, int c)
{
	size_t n;

	n = ft_strlen(s);
	if (s[n] == '\0' && c == 0)
		return (s + n);
	n--;
	while (n > 0 && s[n])
	{
		if (s[n] == (unsigned char)c)
			return (s + n);
		else
			n--;
	}
	return (NULL);
}

