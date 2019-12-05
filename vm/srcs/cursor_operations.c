/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:31:16 by svoort         #+#    #+#                */
/*   Updated: 2019/12/05 17:11:41 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern		t_op	op_tab[17];

void		assign_new_opcode(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	cursor->opcode = arena[cursor->position % MEM_SIZE];
	cursor->wait_cycles = op_tab[cursor->opcode - 1].wait_cycles;
}

void		check_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	if (is_valid_operation(cursor, arena))
	{
		if (cursor->wait_cycles == 0)
			assign_new_opcode(cursor, arena);
		if (validate_registry_numbers(cursor, arena) && validate_encoding_byte(cursor, arena))
			execute_operation(cursor, arena); //dees
		move_cursor_to_next_operation(cursor, arena); //dees
		return ;
	}
	move_cursor_to_next_byte(cursor, arena);
	return ;
}

void		decrease_wait_cycles(t_cursor *cursor)
{
	if (cursor->wait_cycles > 0)
		cursor->wait_cycles++;
}

void		execute_cursors(t_vm *vm)
{
	t_cursor	*to_execute;

	to_execute = vm->cursors;
	while (to_execute)
	{
		if (to_execute->wait_cycles == 0)
			check_operation(to_execute, vm->arena);
		decrease_wait_cycles(to_execute);
		to_execute = to_execute->next;
	}
}
