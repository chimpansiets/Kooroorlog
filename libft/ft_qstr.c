/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_qstr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 17:42:59 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:14:27 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_qstr(char *s, int *i)
{
	char		*res;
	int			j;

	j = 0;
	if (i[11] < 0 || i[11] > (int)ft_strlen(s))
		res = ft_strdup(s);
	else
		ft_qstr_help(&res, i, &j, s);
	i[10] -= (int)ft_strlen(res) - 1;
	if (i[3] != 2)
	{
		i[13] = 1;
		strendf(res[0], i);
	}
	if (res[i[13]] && res[0])
		i[1] += write(1, &res[i[13]], ft_strlen(&res[i[13]]));
	while ((i[10] - 1) > 0)
	{
		i[10] -= 1;
		i[1] += write(1, " ", 1);
	}
	free(res);
	return (s);
}

static	char	*ft_rotng(char *s, int i)
{
	char		*r;
	char		*res;
	int			a;

	if (!*s)
		return (0);
	i = -i;
	r = (char *)malloc(ft_strlen(s) + 1);
	if (!(r))
		return (0);
	res = r;
	while (*s)
		ft_rotng_loop(&a, i, &s, &r);
	*r = '\0';
	return (res);
}

char			*ft_rotnb(char *s, int i)
{
	char		*r;
	char		*res;
	int			a;

	if (i < 0 || !*s)
		return (ft_rotng(s, i));
	r = (char *)malloc(ft_strlen(s) + 1);
	if (!(r))
		return (0);
	res = r;
	while (*s)
		ft_rotnb_loop(&a, i, &s, &r);
	*r = '\0';
	return (res);
}

static	void	outunsec(char *s, int *i, int j, int c)
{
	while (i[11] != -2 && (i[16] - 1) > 0)
	{
		i[16] -= 1;
		if (!s[j])
		{
			i[16] -= 1;
			j++;
		}
		s[c] = s[j];
		c++;
		j++;
	}
	s[c] = '\0';
	if (i[10] > (int)ft_strlen(s))
	{
		while (i[3] == 2 && i[10] > (int)ft_strlen(s))
			s = ft_joinfree(s, " ", 1);
		while (i[3] == 1 && i[10] > (int)ft_strlen(s))
			s = ft_joinfree("0", s, 0);
		while (i[10] > (int)ft_strlen(s))
			s = ft_joinfree(" ", s, 0);
	}
	i[1] += write(1, s, ft_strlen(s));
}

void			ft_outun(char *s, int *i, int j, int c)
{
	int			b;

	b = 0;
	if (i[11] > -1)
	{
		while ((i[11] - 1) > -1 && s[j])
		{
			i[11] -= 1;
			j++;
			if ((i[16] - 1) > 0 && !s[j])
			{
				i[16] -= 1;
				while (s[b])
					ft_outun_loop(&s, &c, &b);
				j++;
				b = j;
			}
			else if (i[16] < 0)
				break ;
		}
		i[11] = -2;
		s[c] = '\0';
	}
	outunsec(s, i, j, c);
}
