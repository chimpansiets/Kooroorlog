/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_bytes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:25:12 by svoort         #+#    #+#                */
/*   Updated: 2019/12/16 18:27:45 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

short	reverse_2bytes(short nb)
{
	unsigned char	*nb_addr;
	unsigned char	reverse_nb[2];

	nb_addr = (unsigned char *)&nb;
	reverse_nb[0] = nb_addr[1];
	reverse_nb[1] = nb_addr[0];
	return (*(short *)&reverse_nb[0]);
}

int		reverse_bytes(int nb)
{
	unsigned char	*nb_addr;
	unsigned char	reverse_nb[4];

	nb_addr = (unsigned char *)&nb;
	reverse_nb[0] = nb_addr[3];
	reverse_nb[1] = nb_addr[2];
	reverse_nb[2] = nb_addr[1];
	reverse_nb[3] = nb_addr[0];
	return (*(int *)reverse_nb);
}
