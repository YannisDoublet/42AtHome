/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:50:00 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/20 19:21:27 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*void	ft_bresenham(int x1, int y1, int x2, int y2, t_test *mlx)
{
	int ex = abs(x2 - x1);
	int ey = abs(y2 - y1);
	int dx = 2 * ex;
	int dy = 2 * ey;
	int Dx = ex;
	int Dy = ey;
	int i = 0;
	int Xincr = 1;
	int Yincr = 1;

	if (x1 > x2)
		Xincr = -1;
	if (y1 > y2)
		Yincr = -1;
	if (Dx > Dy)
	{
		while (i <= Dx)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x1, y1, 0xFF00FF);
			i++;
			x1 += Xincr;
			ex -= dy;
			if (ex < 0)
			{
				y1 += Yincr;
				ex += dx;
			}
		}
	}
	else
	{
		while (i <= Dy)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x1, y1, 0x00FF00);
			i++;
			y1 += Yincr;
			ey -= dx;
			if (ey < 0)
			{
				x1 += Xincr;
				ey += dy;
			}
		}
	}
}*/

int		ft_pixel(int button, int x, int y, t_test *mlx)
{
	static int x1;
	static int y1;
	static int x2;
	static int y2;
	static int i;

	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xFFFFFFF);
	if (i == 0)
	{
		x1 = x;
		y1 = y;
	}
	else if (i == 1)
	{
		x2 = x;
		y2 = y;
	}
	if (i == 1)
	{
		ft_bresenham(x1, y1, x2, y2, mlx);
		i = 0;
		return (0);
	}
	i++;
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xFFFFFFF);
	return (0);
}

int		ft_put_pixel(int key, t_test *mlx)
{
	printf("key : %d\n", key);
	if (key == 123)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x - 1), mlx->y, 0x0000FF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x - 2), mlx->y, 0x0000FF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x - 3), mlx->y, 0x0000FF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x - 4), mlx->y, 0x0000FF);
		mlx->x -= 4;
	}
	else if (key == 124)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x + 1), mlx->y, 0x00FF00);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x + 2), mlx->y, 0x00FF00);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x + 3), mlx->y, 0x00FF00);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (mlx->x + 4), mlx->y, 0x00FF00);
		mlx->x += 4;
	}
	else if (key == 125)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y + 1), 0xFF0000);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y + 2), 0xFF0000);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y + 3), 0xFF0000);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y + 4), 0xFF0000);
		mlx->y += 4;
	}
	else if (key == 126)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y - 1), 0xFFFFFF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y - 2), 0xFFFFFF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y - 3), 0xFFFFFF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x, (mlx->y - 4), 0xFFFFFF);
		mlx->y -= 4;
	}
	return (0);
}

int		main(void)
{
	t_test	*mlx;

	if (!(mlx = malloc(sizeof(t_test))))
		return (-1);
	mlx->x = 10;
	mlx->y = 10;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 500, 500, "Yo c les test mdrr");
	mlx_key_hook(mlx->win_ptr, ft_put_pixel, mlx);
	mlx_mouse_hook(mlx->win_ptr, ft_pixel, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}