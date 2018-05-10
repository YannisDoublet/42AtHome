/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:23:43 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/10 18:11:49 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;

	if (argc > 1)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		get_next_line(fd1, &line);
		ft_putstr(line);
		free (line);
		ft_putchar('\n');
		get_next_line(fd1, &line);
		ft_putstr(line);
		free (line);
		ft_putchar('\n');
	}
	return (0);
}
