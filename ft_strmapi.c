/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannisdo <yannisdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:56:07 by yannisdo          #+#    #+#             */
/*   Updated: 2018/04/15 16:56:07 by yannisdoublet    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *str;
	unsigned int i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	if (s)
	{
		while (s[i])
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
	str[i] = '\0';
	}
	return (str);
}
