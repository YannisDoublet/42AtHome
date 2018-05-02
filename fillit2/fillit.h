/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgelu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:21:37 by tgelu             #+#    #+#             */
/*   Updated: 2018/05/02 15:01:15 by tgelu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include "libft/libft.h"
# include <fcntl.h>

# include <stdio.h>

typedef struct			s_point
{
	int					x;
	int					y;
	char				value;
}						t_point;

typedef struct			s_tetros
{
	struct s_point		**tab;
	struct s_tetros		*next;
	int					len;
	int					placed;
}						t_tetros;

typedef struct          s_map
{
	char			    **tab;
	int					size;
}                       t_map;

int		ft_fillit(char *file_name);
int		ft_check_chars(t_tetros *tetros);
int		ft_check_four(t_tetros *tetros);
int		ft_check_adjacents(t_tetros *tetros);
int		ft_adjacent(t_tetros *tetros, int x, int y);
int		ft_check_len(t_tetros *tetros);
int		*ft_min(t_tetros *tetros);
int		*ft_max(t_tetros *tetros);
void	ft_remap_tetros(t_tetros **tetros);
t_map	*ft_solve(t_tetros *tetros, int size);
int		ft_solve_map(t_tetros *tetros, t_map *map, int size, char c);
int		ft_put_tetros(t_map *map, t_tetros *tetros, t_point *pos, char c);
t_point *ft_new_point(int x, int y);
void	ft_place_point(t_map *map, t_tetros *tetros, t_point *pos, char c);
void	ft_print_map(t_map *map);
#endif
