/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 15:42:11 by svoort         #+#    #+#                */
/*   Updated: 2019/11/02 09:40:10 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	size_t	i;

	dst = (char *)ft_memalloc(sizeof(char) * (n + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i < n)
	{
		dst[i] = ((char *)s1)[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
