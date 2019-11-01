/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isint.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 12:41:25 by svoort         #+#    #+#                */
/*   Updated: 2019/08/20 12:31:21 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isint(const char *str, bool strict)
{
	unsigned int	result;
	unsigned int	border;
	int				i;
	int				sign;
	int				digits;

	result = 0;
	digits = 0;
	border = (unsigned int)(INT_MAX / 10);
	i = 0;
	while (!strict && ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && ++digits)
	{
		if (((result > border || (result == border && (str[i] - '0') > 7))
				&& sign == 1)
			|| ((result > border || (result == border && (str[i] - '0') > 8))
				&& sign == -1))
			return (false);
		result = result * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}
