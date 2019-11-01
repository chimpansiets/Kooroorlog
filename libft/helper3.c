/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/10 16:44:06 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:07:54 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_prfsec(int **i, char c, va_list *ar, char *ito)
{
	i[0][2] = 0;
	if (!(i[0][2]))
		prfsec(c, (*i), ar, ito);
}

void	prfstr_if_c(char s, int **i, char **un, va_list *ar)
{
	if ((s == 'c' || s == 'C'))
	{
		i[0][8] = 9;
		i[0][16] = -1;
		(*un) = unicd(va_arg(*ar, int));
		i[0][10] -= 1;
		if (!(*un))
			*un = ft_strdup("");
		ft_qstr((*un), (*i));
	}
}

void	prfsec_check_r(char *s, int **i)
{
	if (s[**i] == 'R')
		i[0][13] = 16;
	else if (s[**i] == 'r')
		i[0][13] = 8;
	else
		i[0][13] = 2;
}

void	prfoper_readarg(int *i, va_list *ar)
{
	if (i[8] != 2 && i[8] != 1)
		*va_arg(*ar, unsigned int *) = i[1];
	else if (i[8] == 2)
		*va_arg(*ar, int *) = (unsigned short int)i[1];
	else if (i[8] == 1)
		*va_arg(*ar, int *) = (unsigned char)i[1];
}

void	if_ar2(int **i, char *s, va_list *ar2)
{
	if (i[0][15] == 1)
	{
		**i += 1;
		i[0][15] = ft_atoi(&s[**i]);
		while (i[0][15] > 1)
		{
			i[0][15] -= 1;
			va_arg(*ar2, void *);
		}
		**i += ft_nbrlen(i[0][15], 1);
	}
}
