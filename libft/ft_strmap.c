/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannisdo <yannisdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:21:51 by yannisdo          #+#    #+#             */
/*   Updated: 2018/04/15 16:21:52 by yannisdoublet    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	size_t i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	if (s)
	{
		while (s[i])
		{
			str[i] = (*f)(s[i]);
			i++;
		}
	str[i] = '\0';
	}
	return (str);
}
