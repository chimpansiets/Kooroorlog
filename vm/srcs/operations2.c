/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:36:06 by svoort         #+#    #+#                */
/*   Updated: 2019/12/13 12:36:56 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sub(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	char	registry_nb;
	int		write_value;

	write_value = get_value(cursor, arena, 1, VALUE) - get_value(cursor, arena, 2, VALUE);
	registry_nb = get_value(cursor, arena, 3, NUMBER);
	cursor->registries[registry_nb - 1] = write_value;
	set_carry(cursor, write_value);
}

void	and_or_xor(t_cursor *cursor, uint8_t arena[MEM_SIZE], int bitwise)
{
	int 	first;
	int		second;
	char	registry_nb;
	int		write_value;

	first = get_value(cursor, arena, 1, VALUE);
	second = get_value(cursor, arena, 2, VALUE);
	if (bitwise == AND)
		write_value = first & second;
	else if (bitwise == OR)
		write_value = first | second;
	else if (bitwise == XOR)
		write_value = first ^ second;
	registry_nb = get_value(cursor, arena, 3, NUMBER);
	cursor->registries[registry_nb - 1] = write_value;
	set_carry(cursor, write_value);
}

void	zjmp(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int write_value;

	write_value = get_value(cursor, arena, 1, -1);
	if (cursor->carry == 0)
		return ;
	cursor->position = (cursor->position + write_value % IDX_MOD) % MEM_SIZE;
}

// void	ldi(t_cursor *cursor, uint8_t arena[MEM_SIZE])
// {
	
// }

void	sti(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		write_value;
	int		second;
	int		third;
	char	registry_nb;

	write_value = get_value(cursor, arena, 1, VALUE);
	second = get_value(cursor, arena, 2, VALUE);
	third = get_value(cursor, arena, 3, VALUE);
	registry_nb = cursor->position + (second + third) % IDX_MOD;
	cursor->registries[registry_nb] = write_value;
}