/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper7.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/13 12:16:39 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:08:17 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flg_sec_check(int **i, char *s)
{
	if (s[**i] == 'h' && s[**i + 1] != 'h' && i[0][8] < 2)
	{
		i[0][8] = 2;
		return (1);
	}
	else if (s[**i] == 'h' && s[**i + 1] == 'h' && !i[0][8])
	{
		**i += 1;
		i[0][8] = 1;
		return (1);
	}
	else if (s[**i] == 'j')
	{
		i[0][8] = 3;
		return (1);
	}
	else if (s[**i] == 'l' && s[**i + 1])
	{
		**i += 1;
		i[0][8] = 3;
		return (1);
	}
	return (0);
}

void	read_width(int **i, char *str, va_list tmp[2], va_list varg)
{
	**i += 1;
	i[0][15] = ft_atoi(&str[**i]);
	va_copy(tmp[0], varg);
	va_copy(tmp[1], varg);
	*i += ft_nbrlen(i[0][15], 1) + 1;
}

void	read_args(int **i, va_list tmp[2])
{
	while ((i[0][15] - 1))
	{
		i[0][15] -= 1;
		va_arg(tmp[0], void *);
	}
}

void	set_args_to_zero(int (*i)[19])
{
	i[0][0] += 1;
	i[0][18] = 1;
	while (i[0][18])
	{
		i[0][18] += 1;
		i[0][i[0][18]] = 0;
	}
}
