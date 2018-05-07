/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:23:43 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/07 18:24:00 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd1;
	char	*line;

	if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY);
		while (get_next_line(fd1, &line) > 0)
		{
			ft_putstr(line);
			ft_strdel(&line);
			ft_putchar('\n');
		}
	}
	return (0);
}
