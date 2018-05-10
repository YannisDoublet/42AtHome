/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:26:26 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/10 18:30:14 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_break_read(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_current_to_line(t_list **current, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (((char *)(*current)->content)[i])
	{
		if (((char *)(*current)->content)[i] == '\n')
		{
			*line = ft_strsub(((char *)(*current)->content), 0, i);
			tmp = ft_strdup(((*current)->content) + i + 1);
			free((*current)->content);
			(*current)->content = (void *)tmp;
			return (1);
		}
		i++;
	}
	if (!((char *)(*current)->content)[i])
	{
		*line = ((char *)(*current)->content) + i - 1;
		return (0);
	}
	return (0);
}

t_list	*ft_which_fd(int fd, t_list **head)
{
	t_list	*current;

	current = *head;
	while (current)
	{
		if (fd == (int)current->content_size)
			return (current);
		else
			current = current->next;
	}
	current = ft_lstnew(NULL, fd);
	ft_lstadd(head, current);
	return (current);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_list			*current;
	static	t_list	*head;
	char			*tmp;

	ret = 0;
	ft_bzero(buff, BUFF_SIZE + 1);
	if (!head)
	{
		head = ft_lstnew(buff, fd);
		current = head;
	}
	else
		current = ft_which_fd(fd, &head);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!current->content)
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin((char *)current->content, buff);
		current->content ? free(current->content) : 1;
		current->content = (void *)tmp;
		if (ft_break_read(buff) == 1)
			break ;
	}
	if (ft_current_to_line(&current, line))
		return (1);
	return (0);
}
