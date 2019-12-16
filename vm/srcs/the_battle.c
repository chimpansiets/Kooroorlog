/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   the_battle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:25:47 by svoort         #+#    #+#                */
/*   Updated: 2019/12/16 18:27:26 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		the_battle(t_vm *vm)
{
	int		i;

	print_mem(vm->arena);
	while (check(vm) == 1)
	{
		i = 0;
		while (i < vm->cycles_to_die)
		{
			execute_cursors(vm);
			i++;
		}
		print_mem(vm->arena);
		vm->check_counter++;
	}
	ft_printf("player %i wins", vm->last_alive);
}
