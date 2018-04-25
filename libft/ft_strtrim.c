/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannisdo <yannisdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:46:16 by yannisdo          #+#    #+#             */
/*   Updated: 2018/04/16 19:46:17 by yannisdoublet    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s)
{
	unsigned int		start;
	int					end;

	if (!s)
		return (ft_strnew(ft_strlen(s)));
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == ',' || s[start] == '\n' || s[start]
			== '\t') && s[start])
		start++;
	while ((s[end] == ' ' || s[end] == ',' || s[end] == '\n' || s[end]
			== '\t') && end > (int)start && s[end])
			end--;
	return (ft_strsub(s, start, (end - start + 1)));
}
