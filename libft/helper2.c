/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/10 14:42:59 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:07:50 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prec_helper(int *j, long double *y)
{
	while (*j)
	{
		(*j)--;
		*y /= 10;
	}
}

void	read_arg(int *i, long double *o, va_list *ar)
{
	if (i[5])
		*o = va_arg(*ar, long double);
	else
		*o = va_arg(*ar, double);
}

void	memalloc_ito(int *l, char ***ito)
{
	*l = -1;
	ito[0] = (char **)malloc(sizeof(char *) * 3);
	if (!(ito[0]))
		return ;
}

void	check_sign(char **ito, int **i, char **s)
{
	if (**ito == '0' && !ito[0][1] && !i[0][11])
		(*ito)++;
	else if (i[0][2] == 2 && **ito != '-')
	{
		**s = '+';
		(*s)++;
	}
	else if (i[0][2] == 1 && **ito != '-')
	{
		**s = ' ';
		(*s)++;
	}
	else if (**ito == '-')
	{
		(*ito)++;
		i[0][11] += 1;
		**s = '-';
		(*s)++;
	}
}

void	cpy_while_second_i(char **ito, int **i, char **s)
{
	while (!(i[0][2]) && **ito)
	{
		**s = **ito;
		(*s)++;
		(*ito)++;
	}
}
