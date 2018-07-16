/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:41:29 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/14 18:53:58 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_liste	*ft_newlst(t_stat *buff, t_dir *direct)
{
	t_liste	*file;
	
	if (!(file = (t_liste *)malloc(sizeof(t_liste))))
		return (NULL);
	file->mode = buff->st_mode;
	file->link = buff->st_nlink;
	file->uid =	buff->st_uid;
	file->gid =	buff->st_gid;
	file->size = buff->st_size;
	file->dev =	buff->st_rdev;
	file->T = buff->st_mtime;
	file->name = direct->d_name;
	file->next = NULL;
	return (file);
}

void	ft_addlst(t_liste **alst, t_liste *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_sortlst(t_liste *f1, t_liste *f2)
{
	t_liste *tmp;

	tmp = f1->next;
	f1->next = f2->next;
	f2->next = tmp;
}