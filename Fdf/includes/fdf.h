/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:36:43 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/18 19:50:48 by yadouble         ###   ########.fr       */
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
# include <math.h>
# include "../libft/includes/libft.h"
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define PLUS 24
# define MINUS 27
# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define RESET 15
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23
# define SIX 22

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
	int				xinit;
	int				yinit;
	int				xfin;
	int				yfin;
}					t_pos;

typedef struct		s_map
{
	int				**posx;
	int				**posy;
	struct 	s_point	**tab;
	int				*width;
	int				height;
	int				hzt;
	int				vrt;
	int				alt;
	int				zoom;
	int				pad_x;
	int				pad_y;
	int				color;
	int				color1;
	int				color2;
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

typedef	struct		s_bres
{
					int ex;
					int ey;
					int dx;
					int dy;
					int Dx;
					int Dy;
					int i;
					int xincr;
					int yincr;
}					t_bres;

typedef	struct		s_stc
{
	t_point			point;
	t_map			map;
	t_mlx			mlx;
}					t_stc;

int					ft_fdf(int fd, t_stc *stc);
void				ft_mlx_init(t_stc *stc);
int					ft_read_map(int fd, t_stc *stc);
int					ft_parse_fdf(char *line);
int					ft_count_to_charset(char *str, char c);
int 				ft_create_tab(t_ligne *head, int i, t_stc *stc);
void				ft_init_bres(t_bres *bres, t_pos *pos);
void				ft_bresenham_line_down(t_pos *pos, t_stc *stc);
void				ft_bresenham_line_up(t_bres bres, t_pos *pos, t_stc *stc);	
int					ft_draw(t_stc *stc);
void				mlx_pixel_put_to_image(t_stc *stc, int x, int y, int color);
t_pos				*ft_get_x_positions(t_stc *stc, int x, int y);
void				ft_draw_vertical_lines(t_stc *stc, int x, int y);
t_pos				*ft_get_y_positions(t_stc *stc, int x, int y);
void				ft_draw_horizontal_lines(t_stc *stc, int x, int y);
void				ft_init_keycode(t_stc *stc);
int					ft_keycode(int key, t_stc *stc);
int					ft_mousehook(int button, int x, int y, t_stc *stc);
#endif
