/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 19:26:32 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:05:25 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				flbax(char *s, va_list *ar2, int *i)
{
	if (ar2)
	{
		if_ar2(&i, s, ar2);
		return (1);
	}
	while (*s)
	{
		if (*s == '%' && (*s))
		{
			s++;
			while (OPER(*s) && OPE2(*s) && OPE3(*s) && *s)
			{
				if (*s > 47 && *s < 58 && *(s + 1) == '$')
				{
					i[15] = 1;
					return (1);
				}
				s++;
			}
		}
		s++;
	}
	return (0);
}

static	void	flg_sec(char *s, int *i, va_list *ar2)
{
	int ret;

	ret = flg_sec_check(&i, s);
	if (!(ret) && s[*i] == '*' && (flbax(s, ar2, i)))
	{
		i[10] = va_arg(*ar2, int);
		if (((i[10]) < 0))
		{
			i[10] *= -1;
			i[3] = 2;
		}
	}
	else if (!(ret) && s[*i] > 48 && s[*i] < 58)
	{
		i[10] = ft_atoi(s + *i);
		*i += ft_nbrlen(i[10], 1) - 1;
	}
	else if (!(ret) && s[*i] == '.')
		if_dot(s, &i, ar2);
}

static	void	flg_fir(char *s, va_list *ar, int *i, va_list *ar2)
{
	while (FLSIZ(s[*i]) || FL2(s[*i]))
	{
		if (s[*i] == ' ' && !i[2])
			i[2] = 1;
		else if (s[*i] == '+')
			i[2] = 2;
		else if (s[*i] == '-')
			i[3] = 2;
		else if (s[*i] == '0' && !i[3])
			i[3] = 1;
		else if (s[*i] == '#')
			i[4] = 1;
		else if (s[*i] == 'L')
			i[5] = 1;
		else if (s[*i] == 'z')
			i[6] = 1;
		else if (s[*i] == 'l' && s[*i + 1] != 'l')
			i[7] = 1;
		else
			flg_sec(s, i, ar2);
		*i += 1;
	}
	ft_prfoper(s, ar, i);
}

static	int		ft_sprintf(char *str, va_list varg, int *i)
{
	va_list		tmp[2];

	while (str[*i])
	{
		if (str[*i] != '%')
			i[1] += write(1, &str[*i], 1);
		else
		{
			read_width(&i, str, tmp, varg);
			read_args(&i, tmp);
			while (i[15])
			{
				i[15] += 1;
				i[i[15]] = 0;
			}
			i[15] = 1;
			i[11] = -1;
			flg_fir((char *)str, tmp, i, &tmp[1]);
		}
		*i += 1;
	}
	va_end(varg);
	return (i[1]);
}

/*
**	Loops through format, whenever it encounters a '%' character,
**	it reads the varg. Stores all flags into an integer array of size 19.
*/

int				ft_printf(const char *format, ...)
{
	int			i[19];
	va_list		varg;

	i[0] = 0;
	i[1] = 0;
	va_start(varg, format);
	if (flbax((char *)format, 0, i))
		return (ft_sprintf((char *)format, varg, i));
	while (format[i[0]])
	{
		if (format[i[0]] != '%')
			i[1] += write(1, &format[i[0]], 1);
		else
		{
			set_args_to_zero(&i);
			i[11] = -1;
			flg_fir((char *)format, &varg, i, &varg);
		}
		i[0] += 1;
	}
	va_end(varg);
	return (i[1]);
}
