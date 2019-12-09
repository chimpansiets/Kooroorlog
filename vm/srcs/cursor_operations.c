/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:31:16 by svoort         #+#    #+#                */
/*   Updated: 2019/12/09 15:57:00 by svoort        ########   odam.nl         */
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
		if (cursor->wait_cycles == -1)
			assign_new_opcode(cursor, arena);
		if (cursor->wait_cycles == 0 && validate_registry_numbers(cursor, arena) && validate_encoding_byte(cursor, arena))
		{
			//execute_operation(cursor, arena); //dees
			move_cursor_to_next_operation(cursor, arena);
			return ;
		}
	}
	move_cursor_to_next_byte(cursor, arena);
	return ;
}

void		decrease_wait_cycles(t_cursor *cursor)
{
	if (cursor->wait_cycles > 0)
		cursor->wait_cycles--;
}

void		check_dump(t_vm *vm)
{
	vm->dump_flag--;
	if (vm->dump_flag == 0)
	{
		print_mem(vm->arena);
		exit(0);
	}
}

void		print_cursor_pos(t_cursor *cursors)
{
	t_cursor	*curr_cursor;

	curr_cursor = cursors;
	while (curr_cursor)
	{
		ft_printf("cursor %i: %i\n", curr_cursor->id, curr_cursor->position);
		curr_cursor = curr_cursor->next;
	}
}

void		execute_cursors(t_vm *vm)
{
	t_cursor	*to_execute;

	to_execute = vm->cursors;
	while (to_execute)
	{
		if (to_execute->wait_cycles == -1)
			check_operation(to_execute, vm->arena);
		if (to_execute->wait_cycles != -1)
			decrease_wait_cycles(to_execute);
		to_execute = to_execute->next;
	}
	print_cursor_pos(vm->cursors);
	check_dump(vm);
}
