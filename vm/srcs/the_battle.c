/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   the_battle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:25:47 by svoort         #+#    #+#                */
/*   Updated: 2020/01/08 12:06:10 by svoort        ########   odam.nl         */
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
			if (ctr == 4265)
				print_cursor(vm);
		}
		vm->check_counter++;
	}
	// print_mem(vm->arena);
	ft_printf("player %i wins\n", -(vm->last_alive));
}
