/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgelu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:37:12 by tgelu             #+#    #+#             */
/*   Updated: 2018/05/02 12:23:46 by tgelu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     *ft_max(t_tetros *tetros)
{
	int     *max;
	int     x;
	int     y;

	max = (int *)malloc(sizeof(int) * 2);
	y = -1;
	max[0] = 0;
	max[1] = 0;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tetros->tab[y][x].value == '#')
			{
				if (x > max[0])
					max[0] = x;
				if (y > max[1])
					max[1] = y;
			}
		}
	}
	return (max);
}

int		*ft_min(t_tetros *tetros)
{
	int		*min;
	int		x;
	int		y;
	int		minx;
	int		miny;

	y = -1;
	minx = 4;
	miny = 4;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tetros->tab[y][x].value == '#')
			{
				if (x < minx)
					minx = x;
				if (y < miny)
					miny = y;
			}
		}
	}
	return ((int[2]){ minx, miny });
}

void	ft_remap_tetros(t_tetros **tetros)
{
	int			x;
	int			y;
	int			*min;
	int			minx;
	int			miny;

	while (*tetros)
	{
		min = ft_min(*tetros);
		minx = min[0];
		miny = min[1];
		y = -1;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
				if ((*tetros)->tab[y][x].value == '#')
				{
					(*tetros)->tab[y][x].value = '.';
					(*tetros)->tab[y - miny][x - minx].value = '#';
				}
		}
		*tetros = (*tetros)->next;
	}
}
