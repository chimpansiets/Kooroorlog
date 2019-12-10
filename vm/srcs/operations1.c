/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 12:47:57 by svoort         #+#    #+#                */
/*   Updated: 2019/12/10 16:41:34 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	report_player_live(t_player *players, int id)
{
	t_player *curr_player = players;
	while (curr_player)
	{
		if (curr_player->id == id)
		{
			curr_player->last_alive = 0;
			return ;
		}
		curr_player = curr_player->next;
	}
}

void	live(t_cursor *cursor, t_vm *vm, uint8_t arena[MEM_SIZE])
{
	int				argument;
	unsigned char	*reverse_argument;

	argument = *((int *)&arena[cursor->position + 1]);
	argument = reverse_bytes(argument);
	if (-(vm->total_players) <= argument && argument <= -1)
	{
		report_player_live(vm->players, argument);
		vm->last_alive = argument;
	}
	vm->live_counter++;
	cursor->last_live = 0;
}
