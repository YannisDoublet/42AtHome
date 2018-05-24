/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:49:42 by yadouble          #+#    #+#             */
/*   Updated: 2018/05/18 18:45:20 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_type_valid(const char *str, t_var *var)
{
	int		i;
	i = var->prtf.i;
	while (str[i])
	{
		if (((str[i] == 's') || (str[i] == 'S') ||
			(str[i] == 'p') || (str[i] == 'd') ||
			(str[i] == 'D') || (str[i] == 'i') ||
			(str[i] == 'o') || (str[i] == 'O') ||
			(str[i] == 'u') || (str[i] == 'U') ||
			(str[i] == 'x') || (str[i] == 'X') ||
			(str[i] == 'c') || (str[i] == 'C')) && 
			((!str[i + 1]) || (str[i + 1] == '%')))
		{
			var->prtf.type = str[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_is_flag_valid(const char *str, t_var *var)
{
	var->prtf.flags = 0;
	while ((str[var->prtf.i] == '-') || (str[var->prtf.i] == '+') ||
		(str[var->prtf.i] == ' ') || (str[var->prtf.i] == '#') ||
		(str[var->prtf.i] == '0'))
	{
		if (str[var->prtf.i] == '-')
			var->prtf.flags |= 1;
		if (str[var->prtf.i] == '+')
			var->prtf.flags |= 1 << 1;
		if (str[var->prtf.i] == ' ')
			var->prtf.flags |= 1 << 2;
		if (str[var->prtf.i] == '#')
			var->prtf.flags |= 1 << 3;
		if (str[var->prtf.i] == '0')
			var->prtf.flags |= 1 << 4; 
		var->prtf.i++;
		var->flag.valid_flag++;
	}
	if (var->flag.valid_flag > 0)
		return (1);
	return (0);
}

int		ft_is_width_valid(const char *str, t_var *var)
{
	var->prtf.width = 0;
	if (str[var->prtf.i] == '*')
	{
		var->prtf.width |= 1;
		var->prtf.i++;
		var->flag.valid_flag++;
	}
	if (str[var->prtf.i] >= '1' && str[var->prtf.i] <= '9')
		var->prtf.w = ft_atoi(str + var->prtf.i);
	if (var->flag.valid_flag > 0)
		return (1);
	return (0);
}

int		ft_is_precision_valid(const char *str, t_var *var)
{
	var->prtf.precision = 0;
	while (str[var->prtf.i] == '.' || str[var->prtf.i] == '*')
	{
		if (str[var->prtf.i] == '.')
			var->prtf.precision |= 1;
		if (str[var->prtf.i] == '*')
			var->prtf.precision |= 1 << 1;
		var->prtf.i++;
		var->flag.valid_flag++;
	}
	if (var->flag.valid_flag > 0)
		return (1);
	return (0);
}

int		ft_is_size_valid2(const char *str, t_var *var)
{
	if (str[var->prtf.i] == 'l')
	{
		if (str[var->prtf.i + 1] == 'l')
		{
			var->prtf.size |= 1 << 3;
			var->prtf.i += 2;
		}
		else
		{
			var->prtf.size |= 1 << 2;
			var->prtf.i++;
		}
	}
	if (str[var->prtf.i] == 'j')
	{
		var->prtf.size |= 1 << 4;
		var->prtf.i++;
	}
	if (str[var->prtf.i] == 'z')
	{
		var->prtf.size |= 1 << 5;
		var->prtf.i++;
	}
	return (1);
}

int		ft_is_size_valid(const char *str, t_var *var)
{
	var->prtf.size = 0;
	if (str[var->prtf.i] == 'h')
	{
		if (str[var->prtf.i + 1] == 'h')
		{
			var->prtf.size |= 1 << 1;
			var->prtf.i += 2;
			return (1);
		}
		else
		{
			var->prtf.size |= 1;
			var->prtf.i++;
			return (1);
		}
	}
	if (ft_is_size_valid2(str, var) == 1)
		return (1);
	return (0);
}

int		ft_parser(const char *str, t_var *var)
{
	var->prtf.i = 0;
	var->prtf.bix = 0;;
	while (str[var->prtf.i])
	{
		if (str[var->prtf.i] == '%')
		{
			var->prtf.i++;
			if (str[var->prtf.i] == '%')
			{
				var->prtf.buff[var->prtf.bix] = '%';
				var->prtf.i += 2;
			}
			if (ft_is_type_valid(str, var) == 1)
			{
				ft_format(var); 
				if (ft_is_flag_valid(str, var) == 1)
					ft_flags(str, var);
				var->flag.valid_flag = 0;
				if(ft_is_width_valid(str, var) == 1)
					//ft_width(t_var *var);
				var->flag.valid_flag = 0;
				if (ft_is_precision_valid(str, var) == 1)
					//ft_precision(t_var *var);
				var->flag.valid_flag = 0;
				if (ft_is_size_valid(str, var) == 1)
					//ft_size(t_var *var);
				var->flag.valid_flag = 0;
				printf("buffer dans le parser : %s\n", var->prtf.buff);
			}
		}
		var->prtf.i++;
	}
	return (1);
}