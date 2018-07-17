/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:07:52 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 18:06:52 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int 	fd;
	int		ret;

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
