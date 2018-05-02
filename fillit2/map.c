/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgelu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:17:40 by tgelu             #+#    #+#             */
/*   Updated: 2018/05/02 15:26:31 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_alloc_map(int size)
{
	t_map	*map;
	int		i;

	map = ft_memalloc(sizeof(t_map));
	map->tab = ft_memalloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		map->tab[i] = ft_memalloc(sizeof(char) * (size + 1));
		ft_memset(map->tab[i], '.' ,size);
		map->tab[i][size + 1] = '\0';
		i++;
	}
	map->tab[i] = NULL;
	map->size = size;
	return (map);
}

void	ft_free_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->tab[i] != NULL)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
	free(map);
}

t_map	*ft_solve(t_tetros *tetros, int size)
{
	t_map		*map;
	t_tetros	*current;

	current = tetros;
	map = ft_alloc_map(size);
	if (ft_solve_map(current, map, size, 'A') == 0)
	{
		ft_free_map(map);
		return (ft_solve(tetros, ++size));
	}
	return (map);
}

void		ft_place_point(t_map *map, t_tetros *tetros, t_point *pos, char c)
{
	int		*dim;
	int		x;
	int		y;

	dim = ft_max(tetros);
	y = -1;
	while (++y < dim[1] + 1 && y + pos->y < map->size)
	{
		x = -1;
		while (++x < dim[0] + 1 && x + pos->x < map->size)
		{
			if (tetros->tab[y][x].value == '#')
				map->tab[y + pos->y][x + pos->x] = c;
		}
	}
	free(dim);
}

int		ft_put_tetros(t_map *map, t_tetros *tetros, t_point *pos, char c)
{
	int		*dim;
	int		x;
	int		y;
	int		placed;

	placed = 1;
	dim = ft_max(tetros);
	y = -1;
	while (++y < dim[1] + 1)
	{
		x = -1;
		while (++x < dim[0] + 1)
		{
			if (x + pos->x >= map->size || y + pos->y >= map->size)
				return (-1);
			if (tetros->tab[y][x].value == '#' && map->tab[y + pos->y][x + pos->x] != '.')
				placed = 0;
		}
	}
	free(dim);
	if (placed)
	{
		ft_place_point(map, tetros, pos, c);
		return (1);
	}
	return (-1);
}

t_point	*ft_new_point(int x, int y)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	return (new);
}

int		ft_solve_map(t_tetros *tetros, t_map *map, int size, char c)
{
	int		x;
	int		y;
	int		*dim;
	int		*pos;
	t_tetros	*current;

	current = tetros;
	if (current == NULL)
		return (1);
	dim = ft_max(tetros);
	y = -1;
	while (++y < size - dim[1] + 1)
	{
		x = -1;
		while (++x < size - dim[0] + 1)
		{
			ft_put_tetros(map, current, ft_new_point(x, y), c);
			if (ft_solve_map(current->next, map, size, ++c))
				return (1);
			else
				ft_place_point(map, current, ft_new_point(x, y), '.');
		}
	}
	free(dim);
	return (0);
}
