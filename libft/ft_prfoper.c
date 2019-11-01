/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prfoper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 16:50:45 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:07:10 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			strendf(char s, int *i)
{
	if (!s && i[13] != 1 && i[8] != 9)
		*i -= 1;
	else
	{
		if (i[3] == 2)
		{
			if (s)
				i[1] += write(1, &s, 1);
			else
				i[1] += write(1, "\0", 1);
			while ((i[10] - 1) > 0)
			{
				i[10] -= 1;
				i[1] += write(1, " ", 1);
			}
		}
		else
			strendf_help(&i, s);
	}
}

static	int		prstsec(va_list *ar, int *i, char *un, int f)
{
	va_list		rrr;

	va_copy(rrr, *ar);
	if (f && !va_arg(rrr, void *))
		return (1);
	else if (f)
		return (0);
	un = va_arg(*ar, char *);
	if (!(un))
	{
		if (i[11] < 0)
			un = ft_strdup("(null)");
		else
			un = ft_strdup("");
		while (i[11] > (int)ft_strlen(un))
			un = ft_joinfree("0", un, 2);
		ft_qstr(un, i);
		free(un);
	}
	else
		ft_qstr(un, i);
	return (0);
}

static	void	prfstr(char s, va_list *ar, int *i, char *un)
{
	if (i[7] || s == 'S' || s == 'C')
	{
		prfstr_if_c(s, &i, &un, ar);
		if (s == 's' || s == 'S')
		{
			un = unistr(va_arg(*ar, wchar_t *), i);
			if (!(un))
			{
				i[16] = 7;
				un = ft_strdup("(null)");
			}
			ft_outun(un, i, 0, 0);
		}
		free(un);
	}
	else
		prstsec(ar, i, un, 0);
}

static	void	opersec(char *s, va_list *ar, int *i, char *st)
{
	if (OPER(s[*i]) && OPE2(s[*i]) && OPE3(s[*i]))
		strendf(s[*i], i);
	else if (s[*i] == 'Z')
		ft_qstr(ft_rotnb(va_arg(*ar, char *), 42), i);
	else if (s[*i] == 'Y')
		ft_qstr(ft_rotnb(va_arg(*ar, char *), -42), i);
	else if ((s[*i] == 'a' || s[*i] == 'A') && i[5])
		ft_dblhex(va_arg(*ar, long double), i, s[*i]);
	else if (s[*i] == 'a' || s[*i] == 'A')
		ft_dblhex(va_arg(*ar, double), i, s[*i]);
	else if (DEVAL(s[*i]) || DEVA2(s[*i]))
		ft_prfnbr(s[*i], i, ar, st);
	else if (s[*i] == 'p')
	{
		st = ft_itoabase(va_arg(*ar, uintmax_t), 16, 97);
		ft_precforp(st, i);
	}
	else if (s[*i] == 'R' || s[*i] == 'r' || s[*i] == 'B')
	{
		prfsec_check_r(s, &i);
		ft_qstr(ft_itoabase(ft_basetoint(va_arg(*ar, char *), i[13]), 0, 0), i);
	}
	else
		ft_prfdbl(s[*i], i, ar);
}

void			ft_prfoper(char *s, va_list *ar, int *i)
{
	char		*st;
	char		c;

	st = NULL;
	if (s[*i] == 'n')
	{
		if (prstsec(0, 0, 0, 1))
			return ;
		prfoper_readarg(i, ar);
	}
	else if (s[*i] == 'c' || s[*i] == 'C' || s[*i] == 's' || s[*i] == 'S')
	{
		if (!i[7] && s[*i] == 'c')
		{
			c = va_arg(*ar, int);
			i[8] = 9;
			strendf(c, i);
		}
		else
			prfstr(s[*i], ar, i, st);
	}
	else
		opersec(s, ar, i, st);
}
