/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 16:21:24 by svoort         #+#    #+#                */
/*   Updated: 2019/11/27 16:22:17 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi_b(const char *str)
{
	int				i;
	long int		res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (int)(res * 10 + (str[i] - '0'));
		i++;
	}
	return ((int)(res * sign));
}
