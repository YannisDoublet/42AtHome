/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:03:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/06 18:26:44 by yannisdoublet    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putstr(str);
		if (str[i] == '\n')
		{
			str = str + i + 1;
			return (1);
		}
		i++;
	}
	return (0);
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
		if ((ft_print_str(str) == 1))
				return (1);
	}
	return (0);
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
