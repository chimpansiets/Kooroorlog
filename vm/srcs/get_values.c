/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_values.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 12:28:22 by svoort         #+#    #+#                */
/*   Updated: 2019/12/13 12:30:27 by svoort        ########   odam.nl         */
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
			offset += 4;
		i++;
	}
	// ft_printf("cursor_instruction: %s\n", op_tab[cursor->opcode - 1].op_name);
	// ft_printf("cursor %i: %i, %i, %i\n", cursor->id, cursor->argument_position[0], cursor->argument_position[1], cursor->argument_position[2]);
	return (1);
}

void	set_carry(t_cursor *cursor, int write_value)
{
	if (write_value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}

// int		get_value(t_cursor *cursor, uint8_t arena[MEM_SIZE], int argument_nb, int reg_use)
// {
// 	int		offset;
	
// 	if (cursor->type_arguments[argument_nb - 1] == T_REG)
// 	{
// 		if (reg_use == NUMBER)
// 			return ((int)arena[(cursor->position + cursor->has_encoding_byte + 1) % MEM_SIZE]);
// 		else if (reg_use == VALUE)
// 			return (cursor->registries[arena[(cursor->position + cursor->has_encoding_byte + 1) % MEM_SIZE] - 1]);
// 	}
// 	else if (cursor->type_arguments[argument_nb - 1] == T_DIR)
// 	{
// 		if (op_tab[cursor->opcode - 1].label_size == 2)
// 			return ((int)(*((short *)&arena[(cursor->position + cursor->has_encoding_byte + 1) % MEM_SIZE])));
// 		else if (op_tab[cursor->opcode - 1].label_size == 4)
// 			return ((int)(*((int *)&arena[(cursor->position + cursor->has_encoding_byte + 1) % MEM_SIZE])));
// 	}
// 	else if (cursor->type_arguments[argument_nb - 1] == T_IND)
// 	{
// 		offset = *((int *)&arena[(cursor->position + cursor->has_encoding_byte + 1) % MEM_SIZE]);
// 		offset = reverse_bytes(offset) % IDX_MOD;
// 		return (*((int *)&arena[(cursor->position + cursor->has_encoding_byte + offset) % MEM_SIZE]));
// 	}
// }

int		get_value(t_cursor *cursor, uint8_t arena[MEM_SIZE], int argument_nb, int to_truncate)
{
	int label_size;
	int offset;

	label_size = op_tab[cursor->opcode - 1].label_size;
	if (cursor->type_arguments[argument_nb - 1] == T_DIR)
	{
		if (label_size == 2)
			return ((int)(*((short *)&arena[(cursor->position + 1 + cursor->has_encoding_byte) % MEM_SIZE])));
		else
			return ((int)(*((int *)&arena[(cursor->position + 1 + cursor->has_encoding_byte) % MEM_SIZE])));
	}
	else if (cursor->type_arguments[argument_nb - 1] == T_IND)
	{
		offset = *(int *)&arena[(cursor->position)];
		if (to_truncate == 1)
		{
			return (0);
		}
	}
	return (0);
}