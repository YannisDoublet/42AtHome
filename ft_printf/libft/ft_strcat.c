/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:48:18 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 15:47:33 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s1[i])
		i++;
	while (s2[n])
		s1[i++] = s2[n++];
	s1[i] = '\0';
	return (s1);
}
