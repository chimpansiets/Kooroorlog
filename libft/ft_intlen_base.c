/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:46:31 by svoort         #+#    #+#                */
/*   Updated: 2019/11/13 14:53:33 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen_base(int nb, int base)
{
	int i;

	i = 1;
	if (nb == -2147483648 && base == 10)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		if (base == 10)
			i++;
	}
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}
