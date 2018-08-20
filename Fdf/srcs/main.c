/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:39:40 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/20 14:27:34 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		main(int argc, char **argv)
{
	int 	fd;
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.x_size = 800;
	mlx.y_size = 600;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.x_size, mlx.y_size, "Salut les poto dla streetzer !");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			if (ft_fdf(fd, mlx) == -1)
			{
				ft_printf("Map Error !\n");
				return (0);
			}
		}
		else
			ft_printf("Invalid File !\n");
	}
	else
		ft_printf("Usage : ./fdf [*.fdf]\n");
	return (0);
}