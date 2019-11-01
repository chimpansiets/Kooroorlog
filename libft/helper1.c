/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/10 12:44:36 by svoort         #+#    #+#                */
/*   Updated: 2019/07/24 13:57:55 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_binary_magic(long double *c, int **i)
{
	if (*c < 0)
	{
		i[0][18] = 1;
		*c = -(*c);
	}
	while (*c >= 2)
	{
		i[0][16] += 1;
		*c /= 2;
	}
	while (*c != 0 && *c < 1)
	{
		i[0][16] -= 1;
		*c *= 2;
	}
	if (*c != 0)
		*c -= 1;
	if (i[0][11] > -1)
		i[0][17] = i[0][11];
	else
		i[0][17] = 13;
}

void	terminate_b(char ***s, int *j)
{
	if (ft_strlen(s[0][1]) == 13)
		while (s[0][1][*j] == '0')
		{
			(*j)--;
			s[0][1][*j] = '\0';
		}
}

void	ft_ifupper(int *reg, int *tmp)
{
	if (*reg)
	{
		if (*reg < 91 && *reg > 64)
			*tmp = 55;
		else
			*tmp = 87;
	}
}

void	convert_pos(int *i, char **res, intmax_t *c)
{
	while (*i)
	{
		(*i)--;
		res[0][*i] = *c % 10 + 48;
		*c /= 10;
	}
}

void	check_char(char **s, uintmax_t *l, int j, uintmax_t i)
{
	if (s[0][j] > 48 && s[0][j] < 58)
		*l += (s[0][j] - '0') * i;
	else if (s[0][j] > 96)
		*l += (s[0][j] - 'a' - 10) * i;
	else if (s[0][j] > 64)
		*l += (s[0][j] - 'A' - 10) * i;
}
