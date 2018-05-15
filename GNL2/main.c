/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 21:33:50 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/15 15:43:27 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd1;
	char	*line;

	if (argc > 1)
	{
		fd1 = open(argv[1], O_RDONLY);
		get_next_line(fd1, &line);
		ft_putstr(line);
		ft_strdel(&line);
		ft_putchar('\n');
	}
	return (0);
}