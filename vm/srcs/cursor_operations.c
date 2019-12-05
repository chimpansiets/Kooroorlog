/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:31:16 by svoort         #+#    #+#                */
/*   Updated: 2019/12/05 14:51:06 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		assign_new_opcode(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	cursor->opcode = arena[cursor->position % MEM_SIZE];
}

void		check_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	if (operation_needs_encoding_byte(cursor))
	{
		if (validate_coding_byte(cursor, arena) && validate_registry_numbers(cursor, arena))
		{
			execute_operation(cursor, arena);
			move_cursor_to_next_operation(cursor, arena);
			return ;
		}
		move_cursor_to_next_operation(cursor, arena);
		return ;
	}
	move_cursor_to_next_byte(cursor, arena);
	return ;
}

void		execute_cursors(t_vm *vm)
{
	t_cursor	*to_execute;

	to_execute = vm->cursors;
	while (to_execute)
	{
		if (to_execute->wait_cycles == -1)
		{
			assign_new_opcode(to_execute, vm->arena);
			set_wait_cycles(to_execute);
		}
		else if (to_execute->wait_cycles == 0)
			check_operation(to_execute, vm->arena);
		decrease_wait_cycles(to_execute);
		to_execute = to_execute->next;
	}
}
