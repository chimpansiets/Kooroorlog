/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/23 12:19:04 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:05:32 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_if_min(const char **str, int *ng)
{
	if (**str == '-' || **str == '+')
	{
		(*str)++;
		if (**str == '-')
			*ng = -(*ng);
	}
}

int			ft_atoi(const char *str)
{
	int		ng;
	size_t	res;

	res = 0;
	ng = 1;
	while (*str == '\t' || *str == ' ' || *str == '\n' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	ft_if_min(&str, &ng);
	while (*str > 47 && *str < 58)
	{
		if (ng < 0 && (res > 922337203685477580 ||
			(res == 922337203685477580 && *str > 55)))
			return (0);
		if (res > 922337203685477580 ||
			(res == 922337203685477580 && *str > 55))
			return (-1);
		res *= 10;
		res += *str - 48;
		str++;
	}
	return (res * ng);
}
