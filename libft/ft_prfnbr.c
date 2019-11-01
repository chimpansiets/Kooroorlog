/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prfnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 19:23:04 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:07:05 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*checkshar(char *ito, int *i, char c)
{
	char		*res;

	res = ito;
	if (c == 'o' || c == 'O')
	{
		i[10] -= 1;
		if (*ito != '0')
			res = ft_joinfree("0", ito, 2);
	}
	else if (!*ito || (*ito == '0' && !ito[1]))
		return (ito);
	if (!(checkshar_check(&i, c, &res, ito)))
		return (NULL);
	return (res);
}

static	char	*tochsize(char *ito, int *i, int *r)
{
	char		*s;
	char		*res;
	char		*fr;

	s = (char *)malloc(sizeof(char) * (*r + i[11] + 2));
	if (!(s))
		return (0);
	res = s;
	fr = ito;
	check_sign(&ito, &i, &s);
	while (((i[11] - 1) - *r) > -1)
	{
		i[11] -= 1;
		*s = '0';
		s++;
	}
	i[2] = 0;
	cpy_while_second_i(&ito, &i, &s);
	*s = '\0';
	*r = ft_strlen(res);
	if ((*r) && i[3] == 1)
		i[3] = 0;
	free(fr);
	return (res);
}

static	char	*endprf(char *s, int *i, int r, char c)
{
	if (i[11] > -1)
		s = tochsize(s, i, &r);
	if (i[4] && (c == 'X' || c == 'x' || c == 'o' || c == 'O'))
		s = checkshar(s, i, c);
	if (*s != '-' && (i[2] == 2))
		i[10] -= 1;
	else if (i[2] == 1)
	{
		i[1] += write(1, " ", 1);
		i[10] -= 1;
	}
	else if (*s == '-' && i[3] == 1)
	{
		i[14] = 1;
		i[1] += write(1, "-", 1);
	}
	endprf_help(&i, s, r);
	while (i[3] == 1 && (i[10] - 1) - r > -1)
	{
		i[10] -= 1;
		i[1] += write(1, "0", 1);
	}
	if (i[3] != 2)
		i[1] += write(1, &s[i[14]], ft_strlen(&s[i[14]]));
	return (s);
}

void			prfsec(char c, int *i, va_list *ar, char *ito)
{
	if (c == 'o' || c == 'O')
		i[13] = 8;
	else if (c == 'b')
		i[13] = 2;
	else if (c == 'X' || c == 'x')
		i[13] = 16;
	prfsec_help(i, &ito, ar, c);
	if (i[10] > (int)ft_strlen(ito) || i[11] > -1 || i[4])
		ito = endprf(ito, i, ft_strlen(ito), c);
	else if (i[2] == 2)
	{
		i[1] += write(1, "+", 1);
		i[1] += write(1, ito, ft_strlen(ito));
	}
	else if (i[2] == 1)
	{
		i[1] += write(1, " ", 1);
		i[1] += write(1, ito, ft_strlen(ito));
	}
	else
		i[1] += write(1, ito, ft_strlen(ito));
	free(ito);
}

void			ft_prfnbr(char c, int *i, va_list *ar, char *ito)
{
	if ((c == 'd' || c == 'i' || c == 'D'))
	{
		i[13] = 1;
		prfnbr_help(i, &ito, ar, c);
		if (i[10] > (int)ft_strlen(ito) || i[11] > -1)
			ito = endprf(ito, i, ft_strlen(ito), c);
		else if (i[2] == 2 && *ito != '-')
		{
			i[1] += write(1, "+", 1);
			i[1] += write(1, ito, ft_strlen(ito));
		}
		else if (i[2] == 1 && *ito != '-')
		{
			i[1] += write(1, " ", 1);
			i[1] += write(1, ito, ft_strlen(ito));
		}
		else
			i[1] += write(1, ito, ft_strlen(ito));
		free(ito);
	}
	else
		if_prfsec(&i, c, ar, ito);
}
