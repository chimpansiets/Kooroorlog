/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:13:26 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/06 11:27:23 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern	t_op	op_tab[17];

void	move_cursor_to_next_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int	new_position;
	int	i;

	new_position = cursor->position;
	i = 0;
	while (i < op_tab[cursor->opcode - 1].amount_args)
	{
		if (cursor->has_encoding_byte)
		{
			//ander verhaal, moet encoding byte in arena zelf checken.
			
		}
		else
		{
			if (T_REG & op_tab[2].type_args[i])
				new_position += 1;
			else if (T_DIR & op_tab[2].type_args[i])
				new_position += op_tab[cursor->opcode - 1].label_size;
			else if (T_IND & op_tab[2].type_args[i])
				new_position += 4;
		}
		i++;
	}
}

void	move_cursor_to_next_byte(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	cursor->position = (cursor->position + 1) % MEM_SIZE;
}