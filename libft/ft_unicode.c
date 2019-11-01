/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unicode.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 14:06:56 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:07:38 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	uninasc(char *s)
{
	int			i;
	int			sum;
	int			bt;

	i = 8;
	sum = 0;
	bt = 1;
	while (i)
	{
		i--;
		if (s[i] == '1')
			sum += bt;
		bt *= 2;
	}
	return ((char)sum);
}

static	char	lascod(char *s, int y)
{
	int			j;
	char		res[9];

	res[0] = '1';
	j = 8;
	res[j] = '\0';
	while (j > 1)
	{
		--j;
		res[j] = '0';
	}
	while (j < 7)
	{
		j++;
		res[j] = s[y];
		y++;
	}
	return (uninasc(res));
}

static	char	*transcode(char *s, int i, char *res, int c)
{
	int			j;
	char		cd[9];

	cd[8] = '\0';
	cd[c] = '0';
	if (c)
		j = i - (c * 6 - 6);
	else
	{
		j = i;
		i = 1;
	}
	transcode_loops(&c, &cd, &j, s);
	res[j] = uninasc(cd);
	j++;
	c = i;
	while (c > 6)
	{
		c -= 6;
		res[j] = lascod(s, i - (6 + (c / 6) * 6));
		j++;
	}
	res[j] = '\0';
	return (res);
}

char			*unicd(wint_t c)
{
	char		*res;
	char		*s;
	int			i;

	if (c == 0)
		return (0);
	s = ft_itoabase(c, 2, '0');
	i = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * 5);
	if (!(res))
		return (0);
	if (i > 16)
		res = transcode(s, i, res, 4);
	else if (i > 11)
		res = transcode(s, i, res, 3);
	else if (i > 7)
		res = transcode(s, i, res, 2);
	else
		res = transcode(s, i, res, 0);
	free(s);
	return (res);
}

char			*unistr(wchar_t *s, int *j)
{
	int			i;
	char		*str;
	char		*tmp;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * ft_wcharlen(s) + 1);
	if (!(str))
		return (0);
	while (*s)
	{
		tmp = unicd(*s);
		s++;
		while (tmp[i])
			unistr_loop(&str, tmp, &j, &i);
		str[j[16]] = '\0';
		j[16] += 1;
		free(tmp);
		i = 0;
	}
	str[j[16]] = '\0';
	return (str);
}
