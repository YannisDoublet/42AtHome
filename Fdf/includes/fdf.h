/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:36:43 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/15 19:14:52 by yadouble         ###   ########.fr       */
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

typedef	struct	s_ligne
{
	char			*str;
	struct	s_ligne	*next;
	struct	s_ligne	*last;
}				t_ligne;

typedef	struct	s_point
{
	int	height;
	int color;
}				t_point;

int			ft_fdf(int fd);
int			ft_read_map(int fd);
int			ft_parse_fdf(char *line);
int			ft_count_to_charset(char *str, char c);
t_point 	***ft_create_tab(t_ligne *head, int i);
#endif
