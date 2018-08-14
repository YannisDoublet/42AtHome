/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:39:40 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 17:51:46 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (ft_fdf(fd) == -1)
		{
			printf("Map Error\n");
			return (0);
		}
	}
	else
		printf("Usage : ./fdf [*.fdf]\n");
	return (0);
}