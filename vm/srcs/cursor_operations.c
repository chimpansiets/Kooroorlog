/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:31:16 by svoort         #+#    #+#                */
/*   Updated: 2019/12/18 12:23:25 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern		t_op	op_tab[17];

void		assign_new_opcode(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	cursor->opcode = arena[cursor->position % MEM_SIZE];
	cursor->wait_cycles = op_tab[cursor->opcode - 1].wait_cycles - 1;
}

static void	reset_cursor(t_cursor *cursor)
{
	cursor->opcode = 0;
	cursor->argument_position[0] = 0;
	cursor->argument_position[1] = 0;
	cursor->argument_position[2] = 0;
	cursor->type_arguments[0] = 0;
	cursor->type_arguments[1] = 0;
	cursor->type_arguments[2] = 0;
	cursor->has_encoding_byte = 0;
	cursor->encoding_byte = 0;
	cursor->wait_cycles = -1;
}

void		check_operation(t_vm *vm, t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		ret_encoding_bytuh;
	int		ret_reg;
	
	if (is_valid_operation(cursor, arena))
	{
		if (cursor->wait_cycles == -1)
			assign_new_opcode(cursor, arena);
		if (cursor->wait_cycles == 0 && (ret_encoding_bytuh = validate_encoding_byte(cursor, arena)) && \
			initialize_argument_pos(cursor) && (ret_reg = validate_registry_numbers(cursor, arena)))
		{
			// ft_printf("%i\n", cursor->wait_cycles);
			execute_operations(vm, cursor, arena);
			if (cursor->opcode != 9 || cursor->carry == 0)
				move_cursor_to_next_operation(cursor, arena);
			reset_cursor(cursor);
			return ;
		}
		else if (cursor->wait_cycles == 0)
		{
			// ft_printf("ret_encodo: %i, ret_reg: %i\n", ret_encoding_bytuh, ret_reg);
			move_cursor_to_next_byte(cursor, arena);
			reset_cursor(cursor);
			return ;
		}
	}
	if (cursor->wait_cycles == -1)
	{
		move_cursor_to_next_byte(cursor, arena);
		reset_cursor(cursor);
	}
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
		print_mem(vm);
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
		if (to_execute->wait_cycles <= 0)
			check_operation(vm, to_execute, vm->arena);
		if (to_execute->wait_cycles != -1)
			decrease_wait_cycles(to_execute);
		to_execute->last_live++;
		to_execute = to_execute->next;
	}
	vm->cycle_counter++;
	//print_cursor_pos(vm->cursors);
	check_dump(vm);
}
