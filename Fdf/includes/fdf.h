/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:36:43 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/17 20:40:29 by yadouble         ###   ########.fr       */
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

typedef struct		s_map
{
	struct 	s_point	**tab;
	int				*width;
	int				height;
	
}					t_map;

int					ft_fdf(int fd);
int					ft_read_map(int fd, t_map *map);
int					ft_parse_fdf(char *line);
int					ft_count_to_charset(char *str, char c);
int 				ft_create_tab(t_ligne *head, int i, t_map *map);
#endif
