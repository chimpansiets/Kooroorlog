/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper4.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/10 17:59:13 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:08:00 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_dot(char *s, int **i, va_list *ar2)
{
	i[0][11] = 0;
	**i += 1;
	if (s[**i] == '*' && (flbax(s, ar2, *i)))
		i[0][11] = va_arg(*ar2, int);
	else if (s[**i] > 47 && s[**i] < 58)
		i[0][11] = ft_atoi(s + **i);
	else
		**i -= 1;
	while (s[**i] > 47 && s[**i] < 58 && s[**i + 1] > 47 && s[**i + 1] < 58)
		**i += 1;
}

void	ft_qstr_help(char **res, int *i, int *j, char *s)
{
	res[0] = (char *)malloc(sizeof(char) * i[11] + 1);
	if (!(*res))
		return ;
	res[0][i[11]] = '\0';
	while (*j < i[11])
	{
		res[0][*j] = s[*j];
		(*j)++;
	}
}

void	ft_rotng_loop(int *a, int i, char **s, char **r)
{
	*a = i;
	if (**s > 64 && **s < 91)
		while (**s - *a < 65)
			*a -= 26;
	else if (**s > 96 && **s < 123)
		while (**s - *a < 97)
			*a -= 26;
	else
		*a = 0;
	**r = **s - *a;
	(*r)++;
	(*s)++;
}

void	ft_rotnb_loop(int *a, int i, char **s, char **r)
{
	*a = i;
	if (**s > 64 && **s < 91)
		while ((int)**s + *a > 90)
			*a -= 26;
	else if ((int)**s > 96 && **s < 123)
		while ((int)**s + *a > 122)
			*a -= 26;
	else
		*a = 0;
	**r = **s + *a;
	(*r)++;
	(*s)++;
}

void	ft_outun_loop(char **s, int *c, int *b)
{
	s[0][*c] = s[0][*b];
	(*c)++;
	(*b)++;
}
