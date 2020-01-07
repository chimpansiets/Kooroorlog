/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_mem.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 15:54:03 by svoort         #+#    #+#                */
/*   Updated: 2020/01/07 11:35:28 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	cursor_is_here(t_cursor *cursors, int position)
{
	while (cursors)
	{
		if (cursors->position == position)
			return (1);
		cursors = cursors->next;
	}
	return (0);
}

void	print_row(uint8_t arena[MEM_SIZE], int position, int size, t_cursor *cursors)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (cursor_is_here(cursors, position + i))
		{
			ft_printf("\e[1;32m");
			ft_printf("%02x ", arena[position + i]);
			ft_printf("\e[0m");
		}
		else
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
			print_row(vm->arena, i, 32, vm->cursors);
			i += 32;
		}
		else
		{
			print_row(vm->arena, i, 64, vm->cursors);
			i += 64;
		}
		ft_printf("\n");
	}
}
