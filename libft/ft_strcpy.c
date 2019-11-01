/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 10:23:24 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:14:12 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *tmp;

	tmp = dst;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (tmp);
}
