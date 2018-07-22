/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 21:10:28 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/22 16:53:57 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int 	main(int argc, char **argv)
{
	int i;
	wchar_t	s[4];
	char c;

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	setlocale(LC_ALL, "");
	i = printf("%S", s);
	printf("\n%d\n", i);
	i = ft_printf("%S", s);
	printf("\n%d\n", i);
	return (0);
}