/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_mem.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 15:54:03 by svoort         #+#    #+#                */
/*   Updated: 2019/12/17 16:07:07 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_row(uint8_t arena[MEM_SIZE], int position, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_printf("%02x ", arena[position + i]);
		i++;
	}
}

void	print_mem(t_vm *vm)
{
	int		i;
	char	mode;

	i = 0;
	if (ft_strequ(vm->flag, "-dump"))
		mode = 1;
	else
		mode = 2;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%04x : ", i);
		if (mode == 1)
		{
			print_row(vm->arena, i, 32);
			i += 32;
		}
		else
		{
			print_row(vm->arena, i, 64);
			i += 64;
		}
		ft_printf("\n");
	}
}
