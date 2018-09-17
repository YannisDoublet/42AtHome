/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:48:36 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/17 19:32:14 by yadouble         ###   ########.fr       */
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

int		ft_read_map(int fd, t_stc *stc)
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
	stc->map.height = i;
	if (!(stc->map.width = malloc(sizeof(int *) * i + 1)))
		return (0);
	ft_create_tab(head, i, stc);
	return (1);
}

int			ft_fdf(int fd, t_stc *stc)
{
	if (ft_read_map(fd, stc) == 0)
		return (-1);
	ft_mlx_init(stc);
	ft_init_keycode(stc);
	ft_draw(stc);
	return (0);
}
