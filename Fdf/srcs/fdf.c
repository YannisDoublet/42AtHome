/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:48:36 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/16 16:47:37 by yadouble         ###   ########.fr       */
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

t_point		***ft_read_map(int fd)
{
	t_ligne *head;
	t_point	***tab;
	char 	*line;
	int 	i;

	i = 0;
	head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_parse_fdf(line) == -1)
			return (NULL);
		if (!(head = create_maillon(head, line)))
			return (NULL);
		i++;
	}
	tab = ft_create_tab(head, i);
	return (tab);
}

int			ft_fdf(int fd)
{
	t_point ***tab;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if ((tab = ft_read_map(fd)) == NULL)
		return (-1);
	/*while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			ft_printf("y : %d et x : %d height : %d et color %d\n", y, x, tab[y][x]->height, tab[y][x]->color);
			x++;
		}
		ft_printf("\n");
		y++;
	}*/
	return (0);
}