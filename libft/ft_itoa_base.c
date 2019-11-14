/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:42:18 by svoort         #+#    #+#                */
/*   Updated: 2019/11/13 14:43:34 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char		*ft_itoa_base(int nb, int base)
{
	int		check;
	int		i;
	char	*str;
	char	tab[16];

	i = 0;
	check = 0;
	ft_strcpy(tab, "0123456789abcdef");
	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && nb < 0)
		check = 1;
	i = ft_intlen_base(nb, base);
	str = (char *)malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	if (check == 1)
		str[0] = '-';
	while (i > check)
	{
		str[i - 1] = tab[ft_check(nb % base)];
		i--;
		nb /= base;
	}
	return (str);
}
