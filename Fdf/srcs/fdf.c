/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:48:36 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/20 18:02:26 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_ligne		*create_maillon(t_ligne *head, char *line)
{
	t_ligne		*new;

	if (!(new = ft_memalloc(sizeof(t_ligne))))
		return (NULL);
	new->str = ft_strdup(line);
	if (!head)
	{
		head = new;
		new->last = new;
	}
	else
	{
		head->last->next = new;
		head->last = new;
	}
	return (head);
}

int		ft_read_map(int fd, t_map *map)
{
	t_ligne *head;
	char 	*line;
	int 	i;

	i = 0;
	head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_parse_fdf(line) == -1)
			return (0);
		if (!(head = create_maillon(head, line)))
			return (0);
		i++;
	}
	map->height = i;
	if (!(map->width = malloc(sizeof(int *) * i + 1)))
		return (0);
	ft_create_tab(head, i, map);
	return (1);
}

int			ft_fdf(int fd, t_mlx mlx)
{
	t_map	*map;
	int		x;
	int		y;
	int		zoom;

	y = 0;
	x = 0;
	zoom = 50;
	if (!(map = malloc(sizeof(t_map))))
		return (-1);
	if (ft_read_map(fd, map) == 0)
		return (-1);	
	while (y < map->height)
	{
		x = 0;
		while (x < map->width[y])
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr,
			(x * mlx.x_size + map->tab[y][x].height) / map->width[y],
			(y * mlx.y_size + map->tab[y][x].height) / map->height, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
