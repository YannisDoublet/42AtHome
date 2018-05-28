/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 20:38:10 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/28 12:24:39 by yadouble         ###   ########.fr       */
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

typedef struct	s_check
{
	va_list			arg;
	int				flags;
	int				conv;
	char			buff[BUFF_SIZE + 1];
	char			type;
	int				width;
	int				prec;
	int				precwidth;
	int				i;
	int				bix;
	int				len;
	long long int 	nb;
}					t_check;

typedef struct		s_var
{
	t_check			check;
}					t_var;

//----------------------------------PARSER------------------------------------//
int					ft_printf(const char *format, ...);
int					ft_parsing_center(const char *fmt, t_var *var);
int					ft_parsing_control(t_var *var, const char *fmt);
void				ft_parse_flags(const char *fmt, t_var *var);
void				ft_parse_width(const char *fmt, t_var *var);
void				ft_parse_precision(const char *fmt, t_var *var);
void				ft_parse_conv(const char *fmt, t_var *var);
void				ft_parse_type(const char *fmt, t_var *var);
//----------------------------------BUFFER------------------------------------//
void				ft_buffer(t_var *var, char c);
//----------------------------------PROCESS-----------------------------------//
void				ft_process(t_var *var);
void				ft_process_flags(t_var *var);
void				ft_which_conv(t_var *var);
void				ft_process_int(t_var *var);
int					ft_numlen(t_var *var);
void				ft_process_width_and_prec(t_var *var);
#endif