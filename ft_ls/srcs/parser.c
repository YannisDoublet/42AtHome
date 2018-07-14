/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:59:04 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/04 16:40:06 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_check_flags(char *flags, char c)
{
	int	i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_parse_flags(char *flag)
{
	int	i;
	int x;

	i = 0;
	x = 0;
	flags = 0;
	while (flag[++i])
	{
		if ((x = ft_check_flags("lRart1", flag[i])) == -1)
			return (-1);
		flags |= 1 << x;
		if (flag[i] == 'l' || flag[i] == '1')
			flag[i] == 'l' ? flags |= ~32 : ~1;
	}
	return (0);
}

int		ft_parser_control(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		if (ft_parse_flags(av[i]) == -1)
		{
			printf(USAGE"\n");
			return (-1);
		}
	}
	return (0);
}