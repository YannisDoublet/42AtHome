/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 23:03:46 by yadouble          #+#    #+#             */
/*   Updated: 2018/02/18 23:03:48 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int ac, char **av)
{
	int no_error;

	no_error = TRUE;
	if (ac == 10)
	{
		if ((no_error = sudoku(av)) == FALSE)
			no_error = FALSE;
	}
	if (ac != 10 || no_error == FALSE)
	{
		ft_putstr("Error");
		ft_putchar('\n');
	}
	return (0);
}
