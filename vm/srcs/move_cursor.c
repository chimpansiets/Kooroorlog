/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:13:26 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/09 16:02:29 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern	t_op	op_tab[17];

int		get_instruction_size(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	char	エンコードバイト;
	int		instruction_size;
	int		i;

	i = 0;
	エンコードバイト = arena[cursor->position + 1];
	instruction_size = 0;
	while (i < op_tab[cursor->opcode - 1].amount_args)
	{
		if (T_REG & (cursor->encoding_byte >> (6 - (i * 2))))
			instruction_size += 1;
		else if (T_DIR & (cursor->encoding_byte >> (6 - (i * 2))))
			instruction_size += 2;
		else if (T_IND & (cursor->encoding_byte >> (6 - (i * 2))))
			instruction_size += 4;
		i++;
	}
	return (instruction_size);
}

void	move_cursor_to_next_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int	new_position;
	int	i;

	new_position = cursor->position;
	i = 0;
	while (i < op_tab[cursor->opcode - 1].amount_args)
	{
		if (cursor->encoding_byte)
			new_position += get_instruction_size(cursor, arena);
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
	cursor->position = new_position;
}

void	move_cursor_to_next_byte(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	cursor->position = (cursor->position + 1) % MEM_SIZE;
}