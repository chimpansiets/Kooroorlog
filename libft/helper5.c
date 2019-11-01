/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper5.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/10 19:17:39 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:08:06 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	transcode_loops(int *c, char (*cd)[9], int *j, char *s)
{
	while (*c)
	{
		--(*c);
		cd[0][*c] = '1';
	}
	while (cd[0][*c] == '1')
		(*c)++;
	if (*c < 7)
	{
		while (*c < 7)
		{
			(*c)++;
			cd[0][*c] = '0';
		}
		(*c)++;
	}
	else
		(*c)++;
	while (*j > 0 && *c)
	{
		--(*c);
		--(*j);
		cd[0][*c] = s[*j];
	}
}

void	unistr_loop(char **str, char *tmp, int **j, int *i)
{
	str[0][j[0][16]] = tmp[*i];
	(*i)++;
	j[0][16] += 1;
}

void	enddbl_check(int **i, char *s)
{
	if (*s != '-' && (i[0][2] == 2 || (i[0][2] == 1)))
	{
		i[0][1] += write(1, " ", 1);
		i[0][10] -= 1;
	}
	else if (*s == '-' && i[0][3] == 1)
	{
		i[0][14] = 1;
		i[0][1] += write(1, "-", 1);
	}
	if (i[0][3] == 2 && i[0][2] == 2 && *s != '-')
	{
		i[0][1] += write(1, "+", 1);
		i[0][1] += write(1, &s[i[0][14]], ft_strlen(&s[i[0][14]]));
	}
	else if (i[0][3] == 2)
		i[0][1] += write(1, &s[i[0][14]], ft_strlen(&s[i[0][14]]));
}

void	dbltoa_loop(int *i, long double *c, int *j, intmax_t *x)
{
	while ((*i - 1) > -1)
	{
		*c *= 10;
		*i -= 1;
		*j = *c;
		*x = *x * 10 + *j;
		*c -= *j;
	}
}

void	prfdbl_check(int **i, int l, char **ito, char c)
{
	if (i[0][11])
	{
		i[0][1] += write(1, ".", 1);
		i[0][1] += write(1, &ito[1][1], ft_strlen(&ito[1][1]));
	}
	if (l != -1)
	{
		i[0][1] += 4;
		justfree(0, l, c);
	}
}
