/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:39:40 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/13 15:16:21 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		main(int argc, char **argv)
{
	int 	fd;
	t_mlx	*mlx;

	if (!(mlx = malloc(sizeof(*mlx))))
		return (-1);
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
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
