/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_mem.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 15:54:03 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 16:11:11 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_mem(uint8_t *mem)
{
	int	i;

	i = 0;
	ft_printf("[");
	while (i < MEM_SIZE)
	{
		if (mem[i])
			ft_printf("\e[0;31m0x%02X,\e[0m", mem[i]);
		else
			ft_printf("0x%02X,", mem[i]);
		i++;
		if (i % 32 == 0 && i != MEM_SIZE)
			ft_printf("\n");
	}
	ft_printf("]\n");
}
