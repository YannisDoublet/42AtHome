/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:22:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/16 16:45:10 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_count(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && (str[i + 1] == ' ' ||
			!str[i + 1]))
			j++;
		i++;
	}
	return (j);
}

t_point ***ft_create_tab(t_ligne *head, int i)
{
	t_point ***tab;
	int		x;
	int		y;
	t_ligne	*current;

	x = 0;
	y = 0;
	current = head;
	if (!(tab = (t_point ***)malloc(sizeof(t_point **) * (i + 1))))
		return (NULL);
	while (current)
	{
		i = 0;
		x = 0;
		if (!(tab[y] = (t_point **)malloc(sizeof(t_point *) * (ft_count(current->str) + 1))))
			return (NULL);
		while (current->str[i])
		{
			if (!(tab[y][x] = (t_point *)malloc(sizeof(t_point))))
				return (NULL);
			tab[y][x]->height = ft_atoi(current->str + i);
			while (ft_isdigit(current->str[i]) || current->str[i] == '-')
				i++;
			while (!(ft_isdigit(current->str[i])) && current->str[i] &&
				(current->str[i] != '-' || current->str[i] != ','))
				i++;
			if (current->str[i] == '0' && current->str[i + 1] == 'x')
			{
				tab[y][x]->color = ft_atoi_base(current->str + (i + 2),
				"0123456789ABCDEF");
				while (!(current->str[i - 1] == ' ' && ft_isdigit(current->str[i])))
					i++;
			}
			else
				tab[y][x]->color = 0;
			x++;
		}
		tab[y][x] = NULL;
		y++;
		current = current->next;
	}
	tab[y] = NULL;
	return (tab);
}
