/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:48:36 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/19 19:43:32 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_ligne		*create_maillon(t_ligne *head, char *line)
{
	t_ligne		*new;

	if (!(new = ft_memalloc(sizeof(t_ligne))))
		return (NULL);
	new->str = ft_strdup(line);
	if (!new->str)
		return (NULL);
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

int		ft_allocate_check(int i, t_ligne *head, t_stc *stc, char *line)
{
	if (i > 0)
	{
		free(line);
		ft_create_tab(head, stc);
		ft_free_chain_list(head);
	}
	else
		return (-1);
	return (0);
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
			return (-1);
		if (!(head = create_maillon(head, line)))
			return (-1);
		free(line);
		i++;
	}
	stc->map.height = i;
	if (ft_allocate_check(i, head, stc, line) == -1)
		return (-1);
	return (0);
}

int			ft_fdf(int fd, t_stc *stc)
{
	if (ft_read_map(fd, stc) == -1)
		return (-1);
	ft_stc_init(stc);
	ft_init_keycode(stc);
	mlx_hook(stc->mlx.win_ptr, 2, 2, ft_keycode, stc);
	mlx_mouse_hook(stc->mlx.win_ptr, ft_mousehook, stc);
	ft_draw(stc);
	return (0);
}
