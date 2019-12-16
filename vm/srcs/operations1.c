/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 12:47:57 by svoort         #+#    #+#                */
/*   Updated: 2019/12/16 11:59:42 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	report_player_live(t_player *players, int id)
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

//works
void		live(t_cursor *cursor, t_vm *vm, uint8_t arena[MEM_SIZE])
{
	int				argument;
	unsigned char	*reverse_argument;

	argument = *((int *)&arena[cursor->position + 1 % MEM_SIZE]);
	argument = reverse_bytes(argument);
	if (-(vm->total_players) <= argument && argument <= -1)
	{
		report_player_live(vm->players, argument);
		vm->last_alive = argument;
	}
	vm->live_counter++;
	cursor->last_live = 0;
}

//weird stuff
void		ld(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		load_value;
	char	registry_nb;
	
	ft_printf("pos: %i\n", cursor->position);
	load_value = get_value(cursor, arena, 1, TRUNCATE);
	ft_printf("load_value: %i\n", load_value);
	set_carry(cursor, load_value);
	registry_nb = arena[cursor->position + cursor->has_encoding_byte + cursor->argument_position[1]];
	cursor->registries[registry_nb - 1] = load_value;
}

void		st(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		argument_one;
	int		argument_two;

	argument_one = get_value(cursor, arena, 1, VALUE);
	if (cursor->type_arguments[1] == T_REG)
	{
		argument_two = get_value(cursor, arena, 2, NUMBER);
		cursor->registries[argument_two - 1] = argument_two;
	}
	else
		argument_two = *((int *)&arena[(cursor->position + cursor->has_encoding_byte + 1) % MEM_SIZE]);
	cursor->registries[argument_one - 1] = argument_two;
}

void		add(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	char	registry_nb;
	int		write_value;

	write_value = get_value(cursor, arena, 1, VALUE) + get_value(cursor, arena, 2, VALUE);
	registry_nb = get_value(cursor, arena, 3, NUMBER);
	cursor->registries[registry_nb - 1] = write_value;
	set_carry(cursor, write_value);
}
