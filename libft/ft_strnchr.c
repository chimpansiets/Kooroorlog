/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 12:09:47 by svoort         #+#    #+#                */
/*   Updated: 2019/05/25 12:14:40 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int n)
{
	char	*ptr;
	int		i;

	ptr = (char*)s;
	i = 0;
	while (*ptr != '\0')
	{
		if (*ptr == c)
			i++;
		if (i == n)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
