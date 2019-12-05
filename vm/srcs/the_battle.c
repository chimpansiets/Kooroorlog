/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   the_battle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:25:47 by svoort         #+#    #+#                */
/*   Updated: 2019/12/05 14:35:08 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		the_battle(t_vm *vm)
{
	int		i;

	while (check(vm) == 1)
	{
		i = 0;
		while (i < vm->cycles_to_die)
			execute_cursors(vm);
		i++;
	}
}
