/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dblhex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 13:50:22 by svoort         #+#    #+#                */
/*   Updated: 2019/07/24 13:58:23 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	in hexlast, flags are handled. s is temp buffer, i is the int array
**	for storing the flags.
*/

static	void	hexlast(char **s, int *i)
{
	if (i[18] == 1)
		s[0] = ft_joinfree("-", s[0], 2);
	else if (i[2] == 2)
		s[0] = ft_joinfree("+", s[0], 2);
	else if (i[2] == 1)
		s[0] = ft_joinfree(" ", s[0], 2);
	while (i[3] == 1 && ft_strlen(s[0]) + ft_strlen(s[1]) < (size_t)i[10])
		s[0] = ft_joinfree(s[0], "0", 1);
	while (!i[3] && ft_strlen(s[0]) + ft_strlen(s[1]) < (size_t)i[10])
		s[0] = ft_joinfree(" ", s[0], 2);
	while (i[3] == 2 && ft_strlen(s[0]) + ft_strlen(s[1]) < (size_t)i[10])
		s[1] = ft_joinfree(s[1], " ", 1);
	s[0] = ft_joinfree(s[0], s[1], 2);
	i[1] += write(1, s[0], ft_strlen(s[0]));
	free(s[0]);
	free(s);
}

/*
**	This function uses uintmax_t. However, it works with numbers
**	below zero aswell. It passes the unsigned long long to
**	my itoa_base. My itoa base casts it to a normal
**	intmax_t is sys is set to 1. When the cast happens, overflow
**	handles the number itself.
**	ie. 18446744073709551610 turns into -6.
*/

static	void	hexsec(uintmax_t z, char **s, int *i, int y)
{
	int				j;

	j = 12;
	if (i[11] && z != 0)
		s[1] = ft_itoabase(z, 16, y);
	else
		s[1] = ft_strdup("");
	while ((int)ft_strlen(s[1]) < i[11])
		s[1] = ft_joinfree("0", s[1], 2);
	terminate_b(&s, &j);
	s[0] = ft_itoabase(i[16], 1, 0);
	if (s[0][0] != '-')
		s[0] = ft_joinfree("+", s[0], 2);
	s[0] = ft_joinfree(" ", s[0], 2);
	s[0][0] = y + 15;
	s[1] = ft_joinfree(s[1], s[0], 3);
	if (i[11] && s[1][0] != 'p' && s[1][0] != 'P')
		s[1] = ft_joinfree(".", s[1], 2);
	s[1] = ft_joinfree(" ", s[1], 2);
	s[1][0] = i[17] + 48;
	s[0] = ft_strdup("0 ");
	s[0][1] = y + 23;
	hexlast(s, i);
}

void			ft_dblhex(long double c, int *i, int y)
{
	char		**s;

	s = (char **)malloc(sizeof(char *) * 3);
	if (!(s))
		return ;
	s[2] = 0;
	ft_binary_magic(&c, &i);
	while (c != 0)
	{
		i[17] -= 1;
		if (i[17] > -1)
			c *= 16;
	}
	if (c == 0)
		i[17] = 0;
	else if (!i[11] && c + 0.5 >= 1)
		i[17] = 2;
	else
		i[17] = 1;
	hexsec(c + 0.5, s, i, y);
}
