/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:13:26 by avan-rei       #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/12/10 11:24:10 by svoort        ########   odam.nl         */
=======
/*   Updated: 2019/12/09 18:08:22 by avan-rei      ########   odam.nl         */
>>>>>>> 788eb71ed76fb75eb14313d78cc8ff7482b4451d
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
		if ((1 & (cursor->encoding_byte >> (6 - (i * 2)))) == 1)
			instruction_size += 1;
		else if ((2 & (cursor->encoding_byte >> (6 - (i * 2)))) == 2)
			instruction_size += op_tab[cursor->opcode - 1].label_size;
		else if ((3 & (cursor->encoding_byte >> (6 - (i * 2)))) == 3)
			instruction_size += 4;
		i++;
	}
	return (instruction_size + 2);
}

void	move_cursor_to_next_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int	i;

	i = 0;
	while (i < op_tab[cursor->opcode - 1].amount_args)
	{
		if (cursor->encoding_byte)
		{
			cursor->position += get_instruction_size(cursor, arena);
			return ;
		}
		else
		{
			if (T_REG & op_tab[2].type_args[i])
				cursor->position += 1;
			else if (T_DIR & op_tab[2].type_args[i])
				cursor->position += op_tab[cursor->opcode - 1].label_size;
			else if (T_IND & op_tab[2].type_args[i])
				cursor->position += 4;
		}
		i++;
	}
<<<<<<< HEAD
	cursor->position += 1;
=======
	cursor->position = new_position;
	ft_printf("b: cursor %i: %i\n", cursor->id, cursor->position);
>>>>>>> 788eb71ed76fb75eb14313d78cc8ff7482b4451d
}

void	move_cursor_to_next_byte(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	cursor->position = (cursor->position + 1) % MEM_SIZE;
	ft_printf("a: cursor %i: %i\n", cursor->id, cursor->position);
}