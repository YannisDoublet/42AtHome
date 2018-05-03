/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:03:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/03 18:46:32 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		while (str[i])
		{
			ft_putchar(str[i]);
			if (str[i] == '\n')
				break ;
			i++;
		}
		if (str[i] == '\n')
		{
			str = str + i + 1;
			break ;
			return (0);
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd1;
	char	**line;

	if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY);
		while (get_next_line(fd1, line) == 1)
			;
	}
	return (0);
}
