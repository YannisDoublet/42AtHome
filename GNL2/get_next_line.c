/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:26:26 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/11 22:07:52 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			if (!(tmp = ft_strdup(((*current)->content) + i + 1)))
				tmp = ft_strdup((*current)->content) + i;
			free((*current)->content);
			(*current)->content = (void *)tmp;
			return (1);
		}
		i++;
	}
	if (!((char *)(*current)->content)[i])
	{
		*line = ft_strsub(((char *)(*current)->content), 0, i);
		tmp = ft_strdup(((*current)->content) + i);
		free((*current)->content);
		(*current)->content = (void *)tmp;
		return (1);
	}
	return (0);
}

t_list	*ft_which_fd(int fd, t_list **head)
{
	t_list	*current;

	current = *head;
	while (current != NULL)
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
	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	if (!head)
		head = ft_lstnew(buff, fd);
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
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen((char *)current->content))
		return (0);
	if (!ft_current_to_line(&current, line))
		return (0);
	return (1);
}
