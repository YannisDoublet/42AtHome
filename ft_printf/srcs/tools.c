/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:46:56 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/18 19:24:33 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		tmp = str[len];
		str[len] = str[i];
		str[i] = tmp;
		i++;
		len--;
	}
	return (str);
}

char	*ft_itoa_base(t_var *var, char *base_to)
{
	long int	i;
	long int	base_len;
	char		*str;
	long int	cmp;
	long int	numcpy;

	printf("Dans itoa la base : %lld\n", var->conv.d);
	base_len = ft_strlen(base_to);
	i = -1;
	cmp = 0;
	numcpy = var->conv.d;
	while (numcpy > 0)
	{
		numcpy = numcpy / base_len;
		cmp++;
	}
	if (!(str = (char *)malloc(sizeof(base_len) + 2)))
		return (NULL);
	while (++i < cmp)
	{
		str[i] = base_to[(var->conv.d % base_len)];
		var->conv.d = var->conv.d / base_len;
	}
	printf("str dans itoa : %s\n", str);
	return (ft_strrev(str));
}