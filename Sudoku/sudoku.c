/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 23:03:57 by yadouble          #+#    #+#             */
/*   Updated: 2018/02/18 23:04:00 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	display_grid(int grid[9][9])
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (c < 9)
	{
		r = 0;
		while (r < 9)
		{
			if (grid[c][r] == 0)
				ft_putchar('.');
			else
				ft_putchar(grid[c][r] + '0');
			if (r != 8)
				ft_putchar(' ');
			r++;
		}
		ft_putchar('\n');
		c++;
	}
}

int		process(int grid[9][9], int position)
{
	int r;
	int c;
	int nb;

	r = position / 9;
	c = position % 9;
	nb = 1;
	if (position == 9 * 9)
		return (TRUE);
	if (grid[c][r] != 0)
		return (process(grid, position + 1));
	while (nb <= 9)
	{
		if ((check_row(nb, r, grid)) && (check_column(nb, c, grid))
			&& (check_square(nb, r, c, grid)))
		{
			grid[c][r] = nb;
			if (process(grid, position + 1) == TRUE)
				return (TRUE);
		}
		nb++;
		grid[c][r] = 0;
	}
	return (FALSE);
}

void	grid_init(int grid[9][9])
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (c < 9)
	{
		r = 0;
		while (r < 9)
		{
			grid[c][r] = 0;
			r++;
		}
		c++;
	}
}

void	convert(char **av, int grid[9][9])
{
	int r;
	int c;

	r = 0;
	c = 0;
	grid_init(grid);
	while (c < 9)
	{
		r = 0;
		while (r < 9)
		{
			if (av[c + 1][r] >= '0' && av[c + 1][r] <= '9')
				grid[c][r] = av[c + 1][r] - '0';
			r++;
		}
		c++;
	}
}

int		sudoku(char **av)
{
	int grid[9][9];

	if ((error(av)) == FALSE)
		return (FALSE);
	convert(av, grid);
	if (!(process(grid, 0)))
		return (FALSE);
	display_grid(grid);
	return (TRUE);
}
