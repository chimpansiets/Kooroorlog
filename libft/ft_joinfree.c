/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_joinfree.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 14:43:59 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:06:35 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cpy_string1(size_t *i, char **res, char *s1)
{
	while (s1[*i])
	{
		res[0][*i] = s1[*i];
		(*i)++;
	}
}

static void	cpy_string2(size_t i, char **res, char *s2, int *z)
{
	while (s2[*z])
	{
		res[0][i + (*z)] = s2[*z];
		(*z)++;
	}
}

char		*ft_joinfree(char *s1, char *s2, int j)
{
	size_t	i;
	char	*res;
	int		z;

	z = 0;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(i + 1);
	if (!(res))
		return (NULL);
	res[i] = '\0';
	i = 0;
	cpy_string1(&i, &res, s1);
	cpy_string2(i, &res, s2, &z);
	if (j == 3 || j == 1)
		free(s1);
	if (j == 3 || j == 2)
		free(s2);
	return (res);
}
