/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:23:13 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 16:25:16 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_init(t_vm *vm)
{
	vm->total_players = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
}
