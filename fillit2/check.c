/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgelu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:15:31 by tgelu             #+#    #+#             */
/*   Updated: 2018/05/02 12:50:22 by tgelu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_len(t_tetros *tetros)
{
	t_tetros	*current;
	
	current = tetros;
	while (current->next != NULL)
	{
		current = current->next;
	}
	if (current->len != 20)
		return (-1);
	return (1);
}

int		ft_adjacent(t_tetros *tetros, int x, int y)
{
	t_tetros	*current;
	int			count;

	count = 0;
	current = tetros;
	if (current->tab[y][x].value == '#')
	{
		if (y > 0 && current->tab[y - 1][x].value == '#')
			count++;
		if (x > 0 && current->tab[y][x - 1].value == '#')
			count++;
		if (y < 3 && current->tab[y + 1][x].value == '#')
			count++;
		if (x < 3 && current->tab[y][x + 1].value == '#')
			count++;
	}
	return (count);
}

int		ft_check_adjacents(t_tetros *tetros)
{
	t_tetros	*current;
	int			x;
	int			y;
	int			count;

	current = tetros;
	while (current)
	{
		count = 0;
		y = -1;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
				count += ft_adjacent(current, x, y);
		}
		if (count != 6 && count != 8)
			return (-1);
		current = current->next;
	}
	return (1);
}

int		ft_check_four(t_tetros *tetros)
{
	t_tetros	*current;
	int			x;
	int			y;
	int			count;

	count = 0;
	current = tetros;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (current->tab[y][x].value == '#')
				count++;
			x++;
		}
		y++;
	}
	if (count != 4)
		return (-1);
	return (1);
}

int		ft_check_chars(t_tetros *tetros)
{
	t_tetros	*current;
	int			x;
	int			y;

	current = tetros;
	while (current)
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (current->tab[y][x].value != '.'
						&& current->tab[y][x].value != '#')
					return (-1);
				x++;
			}
			y++;
		}
		current = current->next;
	}
	return (1);
}
