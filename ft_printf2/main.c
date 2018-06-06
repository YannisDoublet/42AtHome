/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 21:10:28 by yadouble          #+#    #+#             */
/*   Updated: 2018/06/06 19:02:40 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int 	main(void)
{
	int i;
	int b;

	i = 0;
	b = 42;
	i = printf("%p", b);
	printf("\n%d\n", i);
	i = ft_printf("%p", b);
	printf("\n%d\n", i);
	return (0);
}