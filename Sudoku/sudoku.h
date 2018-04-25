/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 23:04:06 by yadouble          #+#    #+#             */
/*   Updated: 2018/02/18 23:04:08 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		check_row(int nb, int r, int grid[9][9]);
int		check_column(int nb, int c, int grid[9][9]);
int		check_square(int nb, int r, int c, int grid[9][9]);
void	display_grid(int grid[9][9]);
void	grid_init(int grid[9][9]);
void	convert(char **av, int grid[9][9]);
int		process(int grid[9][9], int position);
int		sudoku(char **av);
int		error(char **av);

#endif
