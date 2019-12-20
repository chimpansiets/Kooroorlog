/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy_corewar.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 16:28:55 by svoort         #+#    #+#                */
/*   Updated: 2019/12/20 15:52:44 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//CHESCO'S MEMMOVE

void	*ft_memcpy_corewar(uint8_t arena[MEM_SIZE], int position, void *to_write, int size)
{
	int				i;
	unsigned char	*cpy;

	cpy = (unsigned char*)to_write;
	i = 0;
	while(i < size)
	{
		arena[(position + i) % MEM_SIZE] = cpy[i];
		i++;
	}
	return (&arena[position]);
}
