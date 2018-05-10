/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:03:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/08 19:30:22 by yannisdoublet    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_str_to_line(char **str,char **line)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			*line = ft_strsub((*str), 0, i);
			*str = *str + i + 1;
			return (1);
		}
		i++;
	}
	if ((*str)[i] == '\0')
	{
		*line = ft_strsub((*str), 0, i);
		return (0);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*str;
	char					buff[BUFF_SIZE + 1];
	int						ret;
	int						i;

	i = 0;
	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
			str = ft_strjoin(str, buff);
	}
	if (ft_str_to_line(&str, line) && ret != -1)
		return (1);
	return (0);
}
