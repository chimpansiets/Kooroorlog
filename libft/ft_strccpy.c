/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 13:07:11 by svoort         #+#    #+#                */
/*   Updated: 2019/10/31 13:08:38 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *dst, const char *src, char c)
{
	size_t	strlen;
	size_t	i;

	i = 0;
	strlen = ft_strlen((char*)src);
	while (src[i] != c)
	{
		if (i >= strlen)
			dst[i] = '\0';
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}
