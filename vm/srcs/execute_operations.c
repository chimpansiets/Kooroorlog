/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_operations.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 12:30:14 by svoort         #+#    #+#                */
/*   Updated: 2019/12/16 18:27:27 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		execute_operations(t_vm *vm, t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int Opekōdo;

	Opekōdo = cursor->opcode;
	if (Opekōdo == 1)
		live(cursor, vm, arena);
	else if (Opekōdo == 2)
		ld(cursor, arena);
	else if (Opekōdo == 3)
		st(cursor, arena);
	else if (Opekōdo == 4)
		add(cursor, arena);
	else if (Opekōdo == 5)
		sub(cursor, arena);
	else if (Opekōdo == 6)
		and_or_xor(cursor, arena, AND);
	else if (Opekōdo == 7)
		and_or_xor(cursor, arena, OR);
	else if (Opekōdo == 8)
		and_or_xor(cursor, arena, XOR);
	else if (Opekōdo == 9)
		zjmp(cursor, arena);
	else if (Opekōdo == 10)
		ldi(cursor, arena);
	else if (Opekōdo == 11)
		sti(cursor, arena);
	else if (Opekōdo == 12)
		fork_corewar(vm, cursor, arena);
	else if (Opekōdo == 13)
		lld(cursor, arena);
	else if (Opekōdo == 14)
		lldi(cursor, arena);
	else if (Opekōdo == 15)
		lfork(vm, cursor, arena);		
	else if (Opekōdo == 16)
		aff(cursor, arena);
}