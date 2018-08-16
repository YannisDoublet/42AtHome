/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:20:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/16 13:41:43 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi_base(char *nbr, char *base_from)
{
	long int	i;
	long int	c;
	long int	neg;
	long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || (nbr[i] == ' '))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		neg = ((nbr[i] == '-') ? -1 : 1);
		i++;
	}
	while (nbr[i] && nbr[i] != '-' && nbr[i] != '+' &&
		((nbr[i] >= '0' && nbr[i] <= '9') || (nbr[i] >= 'A' && nbr[i] <= 'F')))
	{
		c = 0;
		while (base_from[c] != nbr[i])
			c++;
		res = (res * ft_strlen(base_from)) + c;
		i++;
	}
	return (res * neg);
}