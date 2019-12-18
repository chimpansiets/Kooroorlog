/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_values.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 12:28:22 by svoort         #+#    #+#                */
/*   Updated: 2019/12/18 17:40:31 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern t_op	op_tab[17];

int		initialize_argument_pos(t_cursor *cursor)
{
	int	i;
	int	offset;

	i = 0;
	offset = 1;
	while (i < 3)
	{
		if (cursor->type_arguments[i] != 0)
			cursor->argument_position[i] = offset;
		if (cursor->type_arguments[i] == T_REG)
			offset += 1;
		else if (cursor->type_arguments[i] == T_DIR)
			offset += op_tab[cursor->opcode - 1].label_size;
		else if (cursor->type_arguments[i] == T_IND)
			offset += 2;
		i++;
	}
	return (1);
}

void	set_carry(t_cursor *cursor, int write_value)
{
	if (write_value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}

int		get_value(t_cursor *cursor, uint8_t arena[MEM_SIZE], int argument_nb, int to_truncate)
{
	int 	label_size;
	short	offset;

	label_size = op_tab[cursor->opcode - 1].label_size;
	if (cursor->type_arguments[argument_nb - 1] == T_DIR)
	{
		if (label_size == 2)
			return ((int)(*((short *)&arena[(cursor->position + cursor->argument_position[argument_nb - 1] + cursor->has_encoding_byte) % MEM_SIZE])));
		else
			return ((int)(*((int *)&arena[(cursor->position + cursor->argument_position[argument_nb - 1] + cursor->has_encoding_byte) % MEM_SIZE])));
	}
	else if (cursor->type_arguments[argument_nb - 1] == T_IND)
	{
		offset = reverse_2bytes(*(short *)&arena[(cursor->position + cursor->argument_position[argument_nb - 1] + cursor->has_encoding_byte) % MEM_SIZE]);
		if (offset < 0 && to_truncate == 1)
			return (*(int *)&arena[(cursor->position + (offset % -(IDX_MOD))) % MEM_SIZE]);
		else if (to_truncate == 1)
			return (*(int *)&arena[(cursor->position + (offset % IDX_MOD)) % MEM_SIZE]);
		else
			return (*(int *)&arena[(cursor->position + offset) % MEM_SIZE]);
	}
	else
		return (cursor->registries[arena[(cursor->position + cursor->has_encoding_byte + cursor->argument_position[argument_nb - 1]) % MEM_SIZE] - 1]);
}
