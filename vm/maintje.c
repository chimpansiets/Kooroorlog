/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maintje.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:37:01 by svoort         #+#    #+#                */
/*   Updated: 2019/12/16 14:33:27 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		reverse_bytes(int nb)
{
	int one;
	int two;

	one = nb >> 8;
	two = nb << 8;
	return (one + two);
}

int	main(void)
{
	short	nb;

	nb = 0xFFBF;
	printf("%i\n", reverse_bytes((short)3));
	return (0);
}