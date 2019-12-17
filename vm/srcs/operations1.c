/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 12:47:57 by svoort         #+#    #+#                */
/*   Updated: 2019/12/17 17:28:00 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	report_player_live(t_player *players, int id)
{
	t_player *curr_player;
	
	curr_player = players;
	while (curr_player)
	{
		if (-(curr_player->id) == id)
		{
			// ft_printf("reporto: %i\n", id);
			curr_player->last_alive = 0;
			return ;
		}
		curr_player = curr_player->next;
	}
}

void		live(t_cursor *cursor, t_vm *vm, uint8_t arena[MEM_SIZE])
{
	int				argument;
	unsigned char	*reverse_argument;

	argument = *((int *)&arena[(cursor->position + 1) % MEM_SIZE]);
	argument = reverse_bytes(argument);
	if (-(vm->total_players) <= argument && argument <= -1)
	{
		report_player_live(vm->players, argument);
		vm->last_alive = argument;
	}
	cursor->last_live = 0;
	vm->live_counter++;
}

void		ld(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		load_value;
	char	registry_nb;
	
	load_value = get_value(cursor, arena, 1, TRUNCATE);
	set_carry(cursor, load_value);
	registry_nb = arena[cursor->position + cursor->has_encoding_byte + cursor->argument_position[1]];
	cursor->registries[registry_nb - 1] = load_value;
}

void		st(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	short	argument_two;
	int 	to_store;

	to_store = get_value(cursor, arena, 1, TRUNCATE_UNDEFINED);
	if (cursor->type_arguments[1] == T_REG)
	{
		argument_two = arena[cursor->position + cursor->has_encoding_byte + cursor->argument_position[1]];
		cursor->registries[argument_two - 1] = to_store;
	}
	else
	{
		argument_two = *((short *)&arena[(cursor->position + cursor->has_encoding_byte + cursor->argument_position[1]) % MEM_SIZE]);
		argument_two = reverse_2bytes(argument_two) % IDX_MOD;
		ft_memcpy_corewar(arena, cursor->position + argument_two, &to_store, 4);
	}
}

void		add(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	char	registry_nb;
	int		value1;
	int		value2;
	int		write_value;

	value1 = reverse_bytes(get_value(cursor, arena, 1, TRUNCATE_UNDEFINED));
	value2 = reverse_bytes(get_value(cursor, arena, 2, TRUNCATE_UNDEFINED));
	write_value = value1 + value2;
	registry_nb = arena[cursor->position + cursor->has_encoding_byte + cursor->argument_position[2]];
	cursor->registries[registry_nb - 1] = reverse_bytes(write_value);
	set_carry(cursor, write_value);
}
