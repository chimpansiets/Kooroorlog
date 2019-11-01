/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcdup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:44:51 by svoort         #+#    #+#                */
/*   Updated: 2019/04/30 14:49:18 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *src, char c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char*)malloc(sizeof(char) * ft_strlen(src));
	while (src[i] && src[i] != c)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
