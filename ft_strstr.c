/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannisdo <yannisdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:59:54 by yannisdo          #+#    #+#             */
/*   Updated: 2018/04/13 16:59:56 by yannisdoublet    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t save;
	size_t n;

	i = 0;
	save = 0;
	n = 0;
	while (haystack[i])
	{
		save = i;
		while (haystack[i] == needle[n])
		{
			if (!needle[n])
				return (haystack + save);
			else
			{
				i++;
				n++;
			}
		}
		n = 0;
		i++;
	}
	return (NULL);
}
