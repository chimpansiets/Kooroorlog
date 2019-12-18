/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   the_battle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:25:47 by svoort         #+#    #+#                */
/*   Updated: 2019/12/18 17:40:23 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		the_battle(t_vm *vm)
{
	int		i;
	int		ctr;

	ctr = 0;
	// print_mem(vm->arena);
	while (check(vm) == 1)
	{
		i = 0;
		while (i < vm->cycles_to_die)
		{
			execute_cursors(vm);
			i++;
			ctr++;
			if (ctr == 2499)
				print_cursor(vm);
		}
		vm->check_counter++;
	}
	// print_mem(vm->arena);
	ft_printf("player %i wins\n", -(vm->last_alive));
}
