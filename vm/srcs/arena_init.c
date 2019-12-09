/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arena_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 13:57:08 by svoort         #+#    #+#                */
/*   Updated: 2019/12/09 16:32:28 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		initialize_cursors(t_vm *vm)
{
	t_player	*curr_player;
	int			id;

	id = vm->total_players;
	curr_player = vm->players;
	while (curr_player)
	{
		if (curr_player->id == id)
		{
			lstadd_cursor(&(vm->cursors), lstnew_cursor(curr_player));
			curr_player = vm->players;
			id--;
		}
		curr_player = curr_player->next;
	}
}

void		place_executable_code(t_vm *vm)
{
	t_player	*curr_player;

	curr_player = vm->players;
	while (curr_player)
	{
		place_player_in_mem(vm, curr_player);
		curr_player = curr_player->next;
	}
}

void		arena_initialization(t_vm *vm)
{
	place_executable_code(vm);
	//print_mem(vm->arena);
	initialize_cursors(vm);
}
