/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 23:03:04 by yadouble          #+#    #+#             */
/*   Updated: 2018/02/18 23:07:08 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		check_row(int nb, int r, int grid[9][9])
{
	int c;

	c = 0;
	while (c < 9)
	{
		if (grid[c][r] == nb)
			return (FALSE);
		c++;
	}
	return (TRUE);
}

int		check_column(int nb, int c, int grid[9][9])
{
	int r;

	r = 0;
	while (r < 9)
	{
		if (grid[c][r] == nb)
			return (FALSE);
		r++;
	}
	return (TRUE);
}

int		check_square(int nb, int r, int c, int grid[9][9])
{
	int s;
	int q;

	s = 0;
	q = 0;
	while (s < 3)
	{
		while (q < 3)
		{
			if (grid[(c - (c % 3)) + q][(r - (r % 3)) + s] == nb)
				return (FALSE);
			q++;
		}
		q = 0;
		s++;
	}
	return (TRUE);
}
