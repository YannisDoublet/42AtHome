/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:36:43 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/13 17:45:06 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
#include <math.h>
# include "../libft/includes/libft.h"

typedef	struct		s_ligne
{
	char			*str;
	struct	s_ligne	*next;
	struct	s_ligne	*last;
}					t_ligne;

typedef	struct		s_point
{
	int				height;
	int 			color;
}					t_point;

typedef	struct		s_pos
{
	double			xinit;
	double			yinit;
	double			xfin;
	double			yfin;
}					t_pos;

typedef struct		s_map
{
	struct 	s_point	**tab;
	int				*width;
	int				height;
	int				hzt;
	int				vrt;
	int				zoom;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;
	int				bpp;
	int				size_line;
	int				endian;
	int				x_size;
	int				y_size;
}					t_mlx;

typedef	struct		s_test
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				x;
	int				y;
}					t_test;

int					ft_fdf(int fd, t_mlx *mlx);
void				ft_mlx_init(t_mlx *mlx);
int					ft_read_map(int fd, t_map *map);
int					ft_parse_fdf(char *line);
int					ft_count_to_charset(char *str, char c);
int 				ft_create_tab(t_ligne *head, int i, t_map *map);
void				ft_bresenham(double x1, double y1, double x2, double y2, t_mlx *mlx);
int					ft_draw(t_mlx *mlx, t_map *map);
void				mlx_pixel_put_to_image(t_mlx *mlx, int x, int y, int color);
t_pos				*ft_get_x_positions(t_mlx *mlx, t_map *map, int x, int y);
void				ft_draw_vertical_lines(t_mlx *mlx, t_map *map, int x, int y);
t_pos				*ft_get_y_positions(t_mlx *mlx, t_map *map, int x, int y);
void				ft_draw_horizontal_lines(t_mlx *mlx, t_map *map, int x, int y);
void				ft_init_keycode(t_map *map, t_mlx *mlx);
int					ft_keycode(int key, t_map *map, t_mlx *mlx);
#endif
