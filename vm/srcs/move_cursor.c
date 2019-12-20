/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:13:26 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/20 12:26:00 by svoort        ########   odam.nl         */
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
	エンコードバイト = cursor->encoding_byte;
	instruction_size = 0;
	while (i < op_tab[cursor->opcode - 1].amount_args)
	{
		if ((3 & (エンコードバイト >> (6 - (i * 2)))) == 3)
			instruction_size += 2;
		else if ((2 & (エンコードバイト >> (6 - (i * 2)))) == 2)
			instruction_size += op_tab[cursor->opcode - 1].label_size;
		else if ((1 & (エンコードバイト >> (6 - (i * 2)))) == 1)
			instruction_size += 1;
		i++;
	}
	return (instruction_size + 2);
}

void	move_cursor_to_next_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int	i;

	i = 0;
	if (cursor->has_encoding_byte)
	{
		cursor->position += get_instruction_size(cursor, arena);
		return ;
	}
	while (i < op_tab[cursor->opcode - 1].amount_args)
	{
		if (op_tab[cursor->opcode - 1].type_args[i] == T_IND)
			cursor->position += 2;
		else if (op_tab[cursor->opcode - 1].type_args[i] == T_DIR)
			cursor->position += op_tab[cursor->opcode - 1].label_size;
		else if (op_tab[cursor->opcode - 1].type_args[i] == T_REG)
			cursor->position += 1;
		i++;
	}
	cursor->position += 1;
}

void	move_cursor_to_next_byte(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	cursor->position = (cursor->position + 1) % MEM_SIZE;
	// ft_printf("a: cursor %i: %i\n", cursor->id, cursor->position);
}