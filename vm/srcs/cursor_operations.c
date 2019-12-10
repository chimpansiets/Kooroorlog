/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:31:16 by svoort         #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/12/10 11:26:16 by svoort        ########   odam.nl         */
=======
/*   Updated: 2019/12/09 18:04:09 by avan-rei      ########   odam.nl         */
>>>>>>> 788eb71ed76fb75eb14313d78cc8ff7482b4451d
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
	int		ret_reg;
	int		ret_encodo_baituh;

	ret_reg = 0;
	ret_encodo_baituh = 0;
	if (is_valid_operation(cursor, arena))
	{
		if (cursor->wait_cycles == -1)
			assign_new_opcode(cursor, arena);
		if (cursor->wait_cycles == 0 && (ret_encodo_baituh = validate_encoding_byte(cursor, arena)) && (ret_reg = validate_registry_numbers(cursor, arena)))
		{
			ft_printf("valid registries and encodo baïtuh\n");
			move_cursor_to_next_operation(cursor, arena);
			cursor->wait_cycles = -1;
			return ;
		}
		else if (cursor->wait_cycles == 0)
		{
			ft_printf("ret_reg: %i\tret_encodo_baituh: %i\n", ret_reg, ret_encodo_baituh);
			move_cursor_to_next_byte(cursor, arena);
		}
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
		if (to_execute->wait_cycles <= 0)
		{
			ft_printf("wait_cycles = %i\n", to_execute->wait_cycles);
			check_operation(to_execute, vm->arena);
		}
		if (to_execute->wait_cycles != -1)
		{
			ft_printf("curr wait_cycles: %i\n", to_execute->wait_cycles);
			decrease_wait_cycles(to_execute);
		}
		to_execute = to_execute->next;
	}
	print_cursor_pos(vm->cursors);
	check_dump(vm);
}
