/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgelu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:21:47 by tgelu             #+#    #+#             */
/*   Updated: 2018/05/02 15:03:25 by tgelu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetros	*ft_create_tetros(char *str)
{
	t_tetros	*ret;
	int			y;
	int			x;

	ret = malloc(sizeof(t_tetros));
	ret->tab = ft_memalloc(sizeof(t_point **));
	y = 0;
	while (y < 4)
	{
		ret->tab[y] = ft_memalloc(sizeof(t_point *));
		x = 0;
		while (x < 4)
		{
			ret->tab[y][x].x = x;
			ret->tab[y][x].y = y;
			ret->tab[y][x].value = str[x + y * 5];
			x++;
		}
		y++;
	}
	ret->len = ft_strlen(str);
	ret->placed = 0;
	ret->next = NULL;
	return (ret);
}

void		ft_print_tetros(t_tetros *tetros)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putchar(tetros->tab[y][x].value);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
}

t_tetros	*ft_get_tetros(char *file_name)
{
	int			fd;
	int			len;
	char		*buff;
	t_tetros	*ret;
	t_tetros	*cpy;

	fd = open(file_name, O_RDONLY);
	ret = NULL;
	if (fd < 0 || !(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE))))
		return (NULL);
	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == NULL)
		{
			ret = ft_create_tetros(buff);
			cpy = ret;
		}
		else
		{
			cpy->next = ft_create_tetros(buff);
			cpy = cpy->next;
		}
		ft_bzero(buff, BUFF_SIZE);
	}
	free(buff);
	return (ret);
}

void		ft_print_map(t_map *map)
{
	int		y;

	y = 0;
	while (map->tab[y])
	{
		ft_putstr(map->tab[y]);
		ft_putchar('\n');
		y++;
	}
}

int			ft_fillit(char *file_name)
{
	t_tetros	*tetros;
	t_tetros	*head;
	t_map		*map;

	if (!(tetros = ft_get_tetros(file_name)))
	{
		ft_putstr("error\n");
		return (-1);
	}
	head = tetros;
	if (ft_check_len(tetros) == -1 || ft_check_chars(tetros) == -1 || ft_check_four(tetros) == -1 || ft_check_adjacents(tetros) == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	ft_remap_tetros(&tetros);
	tetros = head;
	map = ft_solve(head, 4);
	ft_print_map(map);
	return (1);
}
