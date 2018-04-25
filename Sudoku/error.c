/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 23:03:28 by yadouble          #+#    #+#             */
/*   Updated: 2018/02/18 23:03:31 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		check_length(char **av, int c)
{
	int i;

	i = 0;
	while (av[c][i])
		i++;
	if (i == 9)
		return (TRUE);
	return (FALSE);
}

int		check_char(char **av, int r, int c)
{
	char dup;

	dup = 0;
	if (av[c][r] >= '0' && av[c][r] <= '9')
		dup = av[c][r + 1];
	if (dup != '.' && av[c][r] == dup)
		return (FALSE);
	if (av[c][r] == '.' || (av[c][r] >= '0' && av[c][r] <= '9'))
		return (TRUE);
	return (FALSE);
}

int		error(char **av)
{
	int count;
	int r;
	int c;

	count = 0;
	r = 0;
	c = 1;
	while (c < 10)
	{
		count = 0;
		r = 0;
		while (r < 9)
		{
			if ((check_char(av, r, c)) == FALSE)
				return (FALSE);
			count++;
			r++;
		}
		if ((check_length(av, c)) == FALSE)
			return (FALSE);
		c++;
	}
	return (TRUE);
}
