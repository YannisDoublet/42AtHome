/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:22:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/17 17:42:29 by yadouble         ###   ########.fr       */
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

int		ft_create_tab(t_ligne *head, int i, t_stc *stc)
{
	int		x;
	int		y;
	t_ligne	*current;

	y = 0;
	current = head;
	if (!(stc->map.tab = malloc(sizeof(t_point **) * (stc->map.height + 1))))
		return (0);
	while (current)
	{
		i = 0;
		x = 0;
		stc->map.width[y] = ft_count(current->str);
		if (!(stc->map.tab[y] = malloc(sizeof(t_point *) * (stc->map.width[y] + 1))))
			return (0);
		while (current->str[i])
		{
			stc->map.tab[y][x].height = ft_atoi(current->str + i);
			while (ft_isdigit(current->str[i]) || current->str[i] == '-')
				i++;
			while (!(ft_isdigit(current->str[i])) && current->str[i] &&
				current->str[i] != '-')
				i++;
			if (current->str[i] == '0' && current->str[i + 1] == 'x')
			{
				stc->map.tab[y][x].color = ft_atoi_base(current->str + (i + 2),
				"0123456789ABCDEF");
				while (!(current->str[i - 1] == ' ' && ft_isdigit(current->str[i])))
					i++;
			}
			else
				stc->map.tab[y][x].color = 0;
			x++;
		}
		y++;
		current = current->next;
	}
	stc->map.width[y] = 0;
	stc->map.tab[y] = NULL;
	return (1);
}
