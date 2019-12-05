/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   the_battle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:25:47 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 16:35:49 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		the_battle(t_vm *vm)
{
	while (player_alive(vm->players))
	{
		while (vm->cycles_to_die)
		{
			// execute shit
		}
	}
}
