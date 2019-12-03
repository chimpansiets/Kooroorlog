/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_position.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:56:25 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 17:21:25 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	calc_position(t_vm *vm)
{
	t_player	*current;
	int			mem_size;

	current = vm->players;
	mem_size = MEM_SIZE / vm->total_players;
	while (current != NULL)
	{
		current->position = mem_size * (current->id - 1);
		current = current->next;
	}
}