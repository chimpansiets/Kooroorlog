/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit_free.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 12:40:50 by svoort         #+#    #+#                */
/*   Updated: 2019/07/24 12:40:51 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsplit_free(char ***strsplit)
{
	char	**current;

	if (strsplit && *strsplit)
	{
		current = ((*strsplit));
		while ((*current))
			free((*(current++)));
		free((*strsplit));
		(*strsplit) = NULL;
	}
}
