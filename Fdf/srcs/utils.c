/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:22:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 15:36:38 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int		**ft_create_tab(t_ligne *head, int i)
{
	int	**tab;
	int	x;
	int	y;
	int	j;
	t_ligne *current;

	x = 0;
	y = 0;
	current = head;
	if (!(tab = malloc(sizeof(int *) * i)))
		return (NULL);
	while (current)
	{
		i = 0;
		if (!(tab[y] = malloc(sizeof(int) * ft_count(current->str))))
			return (NULL);
		while (current->str[i])
		{
			tab[y][x] = ft_atoi(current->str + i);
			while(ft_isdigit(current->str[i]))
				i++;
			while (!(ft_isdigit(current->str[i])) && current->str[i])
				i++;
			x++;
		}
		x = 0;
		y++;
		current = current->next;
	}
	return (tab);
}