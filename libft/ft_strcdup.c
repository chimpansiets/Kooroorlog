/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcdup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:44:51 by svoort         #+#    #+#                */
/*   Updated: 2019/11/18 12:36:52 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *src, char c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char*)ft_memalloc(sizeof(char) * ft_strlen(src));
	while (src[i] && src[i] != c)
	{
		ret[i] = src[i];
		i++;
	}
	if (src[i] != c)
		return (NULL);
	ret[i] = '\0';
	return (ret);
}
