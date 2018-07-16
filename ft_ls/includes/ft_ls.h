/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:29:46 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/14 18:35:23 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <errno.h>
# include <dirent.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# define USAGE "ft_ls [-lRart] [file ...]"
int		flags;
//-------------------------------STRUCTURES-----------------------------------//
typedef	struct	stat		t_stat;
typedef	struct	passwd		t_passwd;
typedef	struct	group		t_grp;
typedef	struct	dirent		t_dir;
typedef	struct			s_liste
{
	mode_t				mode;
	nlink_t				link;
	uid_t				uid;
	gid_t				gid;
	off_t				size;
	dev_t				dev;
	time_t				T;
	char				*name;
	char				path[PATH_MAX];
	struct s_liste		*next;
}						t_liste;
//--------------------------------PARSING-------------------------------------//
int		ft_parser_control(int ac, char **av);
int		ft_parse_flags(char *flag);
int		ft_check_flags(char *flags, char c);
//-------------------------------PROCESS--------------------------------------//
t_liste	*ft_newlst(t_stat *buff, t_dir *direct);
void	ft_addlst(t_liste **alst, t_liste *new);
void	ft_sortlst(t_liste *f1, t_liste *f2);
#endif