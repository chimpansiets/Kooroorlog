/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_bytes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:25:12 by svoort         #+#    #+#                */
/*   Updated: 2019/12/16 12:25:21 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		reverse_2bytes(int nb)
{
	int one;
	int two;

	one = nb >> 8;
	two = nb << 8;
	return (one + two);
}

int		reverse_bytes(int nb)
{
	int one;
	int two;
	int three;
	int four;

	one = nb >> 24;
	two = nb << 8;
	two = two >> 24;
	two = two << 8;
	three = nb << 16;
	three = three >> 24;
	three = three << 16;
	four = nb << 24;
	return (one + two + three + four);
}
