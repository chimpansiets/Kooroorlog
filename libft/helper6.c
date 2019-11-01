/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper6.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/12 16:33:58 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:08:12 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checkshar_check(int **i, char c, char **res, char *ito)
{
	if (i[0][3] != 1 && (c == 'X' || c == 'x'))
	{
		i[0][10] -= 2;
		(*res) = (char *)malloc(sizeof(char) * ft_strlen(ito) + 3);
		if (!(*res))
			return (0);
		res[0][0] = '0';
		res[0][1] = c;
		res[0][2] = '\0';
		*res = ft_joinfree((*res), ito, 3);
	}
	else if ((c == 'X' || c == 'x'))
	{
		i[0][10] -= 2;
		i[0][1] += ft_printf("0%c", c);
	}
	return (1);
}

void	endprf_help(int **i, char *s, int r)
{
	if (i[0][3] == 2 && i[0][2] == 2 && *s != '-')
	{
		i[0][1] += write(1, "+", 1);
		i[0][1] += write(1, &s[i[0][14]], ft_strlen(&s[i[0][14]]));
	}
	else if (i[0][3] == 2)
		i[0][1] += write(1, &s[i[0][14]], ft_strlen(&s[i[0][14]]));
	while (i[0][3] != 1 && ((i[0][10] - 1) - r > -1))
	{
		i[0][10] -= 1;
		i[0][1] += write(1, " ", 1);
	}
	if (i[0][2] == 2 && *s != '-' && i[0][3] != 2)
		i[0][1] += write(1, "+", 1);
}

void	prfsec_help(int *i, char **ito, va_list *ar, char c)
{
	if (i[6] || i[8] == 3)
		*ito = ft_itoabase(va_arg(*ar, uintmax_t), i[13], c);
	else if (i[7] || c == 79 || c == 85)
		*ito = ft_itoabase(va_arg(*ar, unsigned long), i[13], c);
	else if (!i[8])
		*ito = ft_itoabase(va_arg(*ar, unsigned int), i[13], c);
	else if (i[8] == 2)
		*ito = ft_itoabase((unsigned short)va_arg(*ar, int), i[13], c);
	else if (i[8] == 1)
		*ito = ft_itoabase((unsigned char)va_arg(*ar, int), i[13], c);
}

void	prfnbr_help(int *i, char **ito, va_list *ar, char c)
{
	if (i[6] || i[8] == 3)
		*ito = ft_itoabase(va_arg(*ar, intmax_t), i[13], c);
	else if (i[7] || c == 'D')
		*ito = ft_itoabase(va_arg(*ar, long), i[13], c);
	else if (!i[8])
		*ito = ft_itoabase(va_arg(*ar, int), i[13], c);
	else if (i[8] == 2)
		*ito = ft_itoabase((short)va_arg(*ar, int), i[13], c);
	else if (i[8] == 1)
		*ito = ft_itoabase((signed char)va_arg(*ar, int), i[13], c);
}

void	strendf_help(int **i, char s)
{
	while (i[0][3] == 1 && (i[0][10] - 1) > 0)
	{
		i[0][10] -= 1;
		i[0][1] += write(1, "0", 1);
	}
	while (!i[0][3] && (i[0][10] - 1) > 0)
	{
		i[0][10] -= 1;
		i[0][1] += write(1, " ", 1);
	}
	if (s)
		i[0][1] += write(1, &s, 1);
	else if (i[0][8] == 9)
		i[0][1] += write(1, "\0", 1);
}
