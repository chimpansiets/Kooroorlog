/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maintje.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:37:01 by svoort         #+#    #+#                */
/*   Updated: 2019/12/11 19:08:23 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
