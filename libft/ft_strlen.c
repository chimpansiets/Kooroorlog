/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 09:31:33 by svoort         #+#    #+#                */
/*   Updated: 2019/04/24 12:07:32 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_wcharlen(const wchar_t *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i * 5);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
