/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:38:04 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/17 22:00:44 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 256
# define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
# define BYTE_TO_BINARY(byte)  \
    (byte & 0x80 ? '1' : '0'), \
    (byte & 0x40 ? '1' : '0'), \
    (byte & 0x20 ? '1' : '0'), \
    (byte & 0x10 ? '1' : '0'), \
    (byte & 0x08 ? '1' : '0'), \
    (byte & 0x04 ? '1' : '0'), \
    (byte & 0x02 ? '1' : '0'), \
    (byte & 0x01 ? '1' : '0')
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef	struct	s_prtf
{
	va_list		arg;
	char		buff[BUFF_SIZE + 1];
	int			bix;
	int			flags;
	int			width;
	int			precision;
	int			size;
	char		type;
	int			i;
	int			w;
}				t_prtf;

typedef	struct	s_flags
{
	int			valid_flag;
}				t_flags;

typedef struct 	s_conv
{
	int			d;
	int			c;
	char		*s;
	int			i;
	int			u;
	int			o;
}				t_conv;

typedef	struct	s_var
{
	t_prtf 		prtf;
	t_flags		flag;
	t_conv		conv;
}				t_var;

int				ft_printf(const	char *format, ...);
//---------------------------------PARSING------------------------------------//
int				ft_parser(const char *str, t_var *var);
int				ft_is_flag_valid(const char *str, t_var *var);
int				ft_is_width_valid(const char *str, t_var *var);
int				ft_is_precision_valid(const char *str, t_var *var);
int				ft_is_size_valid(const char *str, t_var *var);
int				ft_is_size_valid2(const char *str, t_var *var);
int				ft_is_type_valid(const char *str, t_var *var);
//-------------------------------CONVERSION-----------------------------------//
//int			ft_minus_flags(const char *str, t_var *var);
void			ft_flags(const char *str, t_var *var);
/*---------------------------------PRINT--------------------------------------*/
void			ft_buffer(t_var *var, char c);
#endif