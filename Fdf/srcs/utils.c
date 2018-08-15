/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:22:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/15 21:47:55 by yadouble         ###   ########.fr       */
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
	if (!(tab = malloc(sizeof(t_point **) * i)))
		return (NULL);
	while (current)
	{
		i = 0;
		if (!(tab[y] = malloc(sizeof(t_point *) * ft_count(current->str))))
			return (NULL);
		while (current->str[i])
		{
			if (!(tab[y][x] = malloc(sizeof(t_point))))
				return (NULL);
			tab[y][x]->height = ft_atoi(current->str + i);
			while (ft_isdigit(current->str[i]))
				i++;
			while (!(ft_isdigit(current->str[i])) && current->str[i])
				i++;
			if (current->str[i] == '0' && current->str[i + 1] == 'x')
			{
				tab[y][x]->color = ft_atoi_base(current->str + (i + 2),
				"0123456789ABCDEF");
				ft_printf("%d\n", tab[y][x]->color);
				while (!(ft_isdigit(current->str[i]) &&
					current->str[i - 1] != ' '))
					i++;
			}
			else
				tab[y][x]->color = 0;
			x++;
		}
		x = 0;
		y++;
		current = current->next;
	}
	return (tab);
}
