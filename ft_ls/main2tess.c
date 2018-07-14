/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2tess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:00:28 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/10 11:55:54 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_stat 		buff;
	t_passwd	*name;
	t_grp		*grp;
	t_dir		*direct;
	t_liste		*file;
	t_liste		**head;
	DIR			*dir;
	char 		*str;
	int 		i;

	i = 0;
	if (!(head = (t_liste **)malloc(sizeof(t_liste *))))
		return (-1);
	dir = opendir(".");
	while ((direct = readdir(dir)))
	{
		stat(direct->d_name, &buff);
		file = ft_newlst(&buff, direct);
		if (i == 0)
			*head = file;
		ft_addlst(head, file);
		i++;
		/*if (ac > 1)
		{
			name = getpwuid(buff.st_uid);
			grp = getgrgid(buff.st_gid);
			i += buff.st_blocks;
			printf("%hu  %s  %s   %lld  %s", buff.st_nlink, name->pw_name, grp->gr_name,
				buff.st_size, ctime(&buff.st_mtime));
		}*/
	}
	file = *head;
	while (file->next)
	{
		printf("%s\n", file->name);
		printf("%lld\n", file->size);
		file = file->next;
		if (file->next == NULL)
		{
			printf("%s\n", file->name);
			printf("%lld\n", file->size);
		}
	}
	//printf("total %d\n", i);
	/*printf("Dernier changement d’état :        %s", ctime(&buff.st_ctime));
    printf("Dernier accès au fichier :         %s", ctime(&buff.st_atime));
    printf("Dernière modification du fichier:  %s", ctime(&buff.st_mtime));*/
	//printf("%d\n", buff.st_dev);      /* ID du périphérique contenant le fichier */
	//printf("%lld\n", buff.st_ino);    /* Numéro inœud */
    //printf("%hu\n", buff.st_mode);    /* Protection */
 	//printf("%hu\n", buff.st_nlink);   /* Nb liens matériels */
	//printf("%u\n", buff.st_uid);      /* UID propriétaire */
	//printf("%u\n", buff.st_gid);      /* GID propriétaire */
    //printf("%d\n", buff.st_rdev);     /* ID périphérique (si fichier spécial) */
    //printf("%lld\n", buff.st_size);   /* Taille totale en octets */
   	//printf("%d\n", buff.st_blksize);  /* Taille de bloc pour E/S */
	//printf("%lld\n", buff.st_blocks); /* Nombre de blocs alloués */
    //printf("%ld\n", buff.st_atime);   /* Heure dernier accès */
    //printf("%ld\n", buff.st_mtime);   /* Heure dernière modification */
    //printf("%ld\n", buff.st_ctime);
	return (0);
}