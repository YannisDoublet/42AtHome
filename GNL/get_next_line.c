/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:03:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/07 15:17:44 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_str_to_line(char **str,char **line)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\n' || (*str)[i] == '\0')
		{
			*line = ft_strsub((*str), 0, i);
			*str = *str + i + 1;
			return (*line);
		}
		i++;
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*str;
	char			*buff;
	int				ret;
	int				i;

	i = 0;
	buff = ft_memalloc(BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
			str = ft_strjoin(str, buff);
	}
	if (ft_str_to_line(&str, line))
			return (1);
	return (0);
}
