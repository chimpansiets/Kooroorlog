/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_operations.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 12:30:14 by svoort         #+#    #+#                */
/*   Updated: 2019/12/10 16:34:22 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		execute_operations(t_vm *vm, t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int Opekōdo;

	Opekōdo = cursor->opcode;
	if (Opekōdo == 1)
		live(cursor, vm, arena);
	// else if (Opekōdo == 2)
	// 	ld();
	// else if (Opekōdo == 3)
	// 	st();
	// else if (Opekōdo == 4)
	// 	add();
	// else if (Opekōdo == 5)
	// 	sub();
	// else if (Opekōdo == 6)
	// 	and();
	// else if (Opekōdo == 7)
	// 	or();
	// else if (Opekōdo == 8)
	// 	xor();
	// else if (Opekōdo == 9)
	// 	zjmp();
	// else if (Opekōdo == 10)
	// 	ldi();
	// else if (Opekōdo == 11)
	// 	sti();
	// else if (Opekōdo == 12)
	// 	fork();
	// else if (Opekōdo == 13)
	// 	lld();
	// else if (Opekōdo == 14)
	// 	lldi();
	// else if (Opekōdo == 15)
	// 	lfork();		
	// else if (Opekōdo == 16)
	// 	aff();
}