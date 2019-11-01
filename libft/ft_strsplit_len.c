/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit_len.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 12:41:06 by svoort         #+#    #+#                */
/*   Updated: 2019/07/24 12:41:07 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strsplit_len(char **strsplit)
{
	size_t	size;

	size = 0;
	if (strsplit)
		while (*strsplit)
		{
			size++;
			strsplit++;
		}
	return (size);
}
