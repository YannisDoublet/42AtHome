/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:38:04 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/15 21:57:00 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 256
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef	struct	s_prtf
{
	va_list		arg;
	char		flags;
	char		width;
	char		precision;
	char		size;
	char		type;
	int			i;
}				t_prtf;

typedef	struct	s_flags
{
	int			valide_flag;	
}				t_flags;

typedef	struct	s_var
{
		t_prtf prtf;
		t_flags	flag;
}				t_var;

int				ft_printf(const	char *format, ...);
//---------------------------------PARSING------------------------------------//
int				ft_parser(const char *str, t_var *var);
int				ft_is_flag_valid(const char *str, t_var *var);
int				ft_is_width_valid(const char *str, t_var *var);
int				ft_is_precision_valid(const char *str, t_var *var);
int				ft_is_size_valid(const char *str, t_var *var);
int				ft_is_type_valid(const char *str, t_var *var);
//-------------------------------CONVERSION-----------------------------------//
#endif