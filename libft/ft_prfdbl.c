/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prfdbl.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 18:54:53 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:06:58 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Frees certain elements of ito, a == 2 it frees entire ito.
**	Note: also tried to handle e and g modifiers, Sounds cool, doesn't work.
*/

int				justfree(char **ito, int a, char c)
{
	if (!ito)
	{
		if (c == 'G' || c == 'E')
			write(1, "E+", 2);
		else
			write(1, "e+", 2);
		ft_printf("%.2d", a);
		return (0);
	}
	if (a)
	{
		free(ito[0]);
		free(ito[1]);
	}
	ito[0] = 0;
	if (a == 2)
		free(ito);
	else if (!(ito[0]))
	{
		ito[1] = 0;
		ito[3] = 0;
	}
	return (0);
}

/*
**	Handles all flags for %f, s is the temp buffer, i is array
**	for storing all flags.
*/

static	char	*enddbl(char *s, int *i, int r, int l)
{
	if (l != -1)
		r += 4;
	enddbl_check(&i, s);
	while (i[3] != 1 && ((i[10] - 1) - r > -2))
	{
		i[10] -= 1;
		i[1] += write(1, " ", 1);
	}
	if (i[2] == 2 && *s != '-' && i[3] != 2)
		i[1] += write(1, "+", 1);
	while (i[3] == 1 && (i[10] - 1) - r > -2)
	{
		i[10] -= 1;
		i[1] += write(1, "0", 1);
	}
	if (i[3] != 2)
		i[1] += write(1, &s[i[14]], ft_strlen(&s[i[14]]));
	return (s);
}

/*
**	dbltoa, just like itoa except with doubles ;)
*/

static	int		dbltoa(long double c, int i, char **s, long double y)
{
	intmax_t	x;
	int			j;

	if (i == -1)
		i = 6;
	j = i;
	prec_helper(&j, &y);
	if (c < 0)
		c -= y;
	else
		c += y;
	x = c;
	s[0] = ft_itoabase(x, 1, '0');
	c -= x;
	if (c < 0)
		c = -c;
	x = 1;
	dbltoa_loop(&i, &c, &j, &x);
	s[1] = ft_itoabase(x, 0, '0');
	if (ft_strlen(s[0]) + ft_strlen(s[1]) > 8)
		return (0);
	return (1);
}

void			ft_precforp(char *s, int *i)
{
	if (i[11] > -1 && i[3] == 1)
		i[3] = 0;
	if (*s == '0' && !s[1] && !i[11])
	{
		free(s);
		s = ft_strdup("0x");
	}
	else
	{
		while (i[3] == 1 && i[10] - 2 > (int)ft_strlen(s))
			s = ft_joinfree("0", s, 2);
		while (i[11] > (int)ft_strlen(s))
			s = ft_joinfree("0", s, 2);
		s = ft_joinfree("0x", s, 2);
	}
	while (i[3] == 2 && i[10] > (int)ft_strlen(s))
		s = ft_joinfree(s, " ", 1);
	while (i[3] != 2 && i[10] > (int)ft_strlen(s))
		s = ft_joinfree(" ", s, 2);
	i[1] += write(1, s, ft_strlen(s));
	free(s);
}

void			ft_prfdbl(char c, int *i, va_list *ar)
{
	long double	o;
	char		**ito;
	int			l;

	memalloc_ito(&l, &ito);
	justfree(ito, 0, 0);
	read_arg(i, &o, ar);
	if (c == 'f' || c == 'F')
		dbltoa(o, i[11], ito, 0.5);
	if ((c == 'e' || c == 'E') || ((c == 'g' || c == 'G') &&
	!(dbltoa(o, i[11], ito, 0.5)) && (justfree(ito, 1, 0))))
	{
		while ((l > -1) && (o >= 10 || o <= -10))
		{
			++l;
			o /= 10;
		}
		dbltoa(o, i[11], ito, 0.5);
	}
	enddbl(ito[0], i, ft_strlen(ito[0]) + ft_strlen(ito[1]) + 1, l);
	prfdbl_check(&i, l, ito, c);
	justfree(ito, 2, 0);
}
