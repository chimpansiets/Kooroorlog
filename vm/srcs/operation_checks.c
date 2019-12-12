/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 15:23:56 by svoort         #+#    #+#                */
/*   Updated: 2019/12/12 14:19:06 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern	t_op	op_tab[17];

int		is_valid_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	if (arena[cursor->position] >= 1 && arena[cursor->position] <= 16)
		return (1);
	else
		return (0);
}

//SIETSE'S FUNCTIE!!!!!
int		validate_registry_numbers(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		i;
	int		reg_number;

	i = 0;
	while (i < op_tab[cursor->opcode - 1].amount_args)
	{
		if (cursor->encoding_byte)
		{
			if (T_REG & (cursor->encoding_byte >> (6 - (i * 2))))
			{
				reg_number = arena[(cursor->position + cursor->has_encoding_byte + i + 1) % MEM_SIZE];
				if (1 <= reg_number && reg_number <= REG_NUMBER)
					return (0);
			}
		}
		else if (T_REG & op_tab[cursor->opcode - 1].type_args[i])
		{
			reg_number = arena[(cursor->position + cursor->has_encoding_byte + i + 1) % MEM_SIZE];
			if (1 <= reg_number && reg_number <= REG_NUMBER)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	bit_shift_gedoe(t_cursor *cursor, int encoding_byte, char op_index)
{
	int i;
	int	offset;

	i = 2;
	offset = 1;
	while (i >= 0)
	{
		encoding_byte = encoding_byte >> 2;
		if ((encoding_byte & 3) == 3)
		{
			if ((op_tab[op_index].type_args[i] & T_IND) != T_IND)
				return (0);
			cursor->type_arguments[i] = T_IND;
		}
		else if ((encoding_byte & 2) == 2)
		{
			if ((op_tab[op_index].type_args[i] & T_DIR) != T_DIR)
				return (0);
			cursor->type_arguments[i] = T_DIR;
		}
		else if ((encoding_byte & 1) == 1)
		{
			if ((op_tab[op_index].type_args[i] & T_REG) != T_REG)
				return (0);
			cursor->type_arguments[i] = T_REG;
		}
		else if (i < op_tab[op_index].amount_args)
			return (0);
		i--;
	}
	return (1);
}


int		validate_encoding_byte(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	if (op_tab[arena[cursor->position] - 1].has_encoding_byte)
	{
		cursor->encoding_byte = arena[(cursor->position + 1) % MEM_SIZE];
		if (cursor->encoding_byte & 3)
			return (0);
		if (!(bit_shift_gedoe(cursor, cursor->encoding_byte, arena[cursor->position % MEM_SIZE] - 1)))
			return (0);
		cursor->has_encoding_byte = 1;
	}
	return (1);
}


//CHESCO'S FUNCTIE!!!!!!!
// int		validate_encoding_byte(t_cursor *cursor, uint8_t arena[MEM_SIZE])
// {
// 	int	amount_args;
// 	int	i;

// 	if (op_tab[arena[cursor->position] - 1].has_encoding_byte)
// 	{
// 		i = 0;
// 		amount_args = op_tab[arena[cursor->position] - 1].amount_args;
// 		cursor->encoding_byte = arena[(cursor->position + 1) % MEM_SIZE];
// 		while (i < 3)
// 		{
// 			if (i < amount_args)
// 			{
// 				if ((op_tab[arena[cursor->position] - 1].type_args[i] & T_REG) == 1)
// 				{
// 					if ((cursor->encoding_byte >> (6 - i * 2) & 1) != 1)
// 						return (0);
// 				}
// 				else if ((op_tab[arena[cursor->position] - 1].type_args[i] & T_DIR) == 2)
// 				{
// 					if ((cursor->encoding_byte >> (6 - i * 2) & 2) != 2)
// 						return (0);
// 				}
// 				else if ((op_tab[arena[cursor->position] - 1].type_args[i] & T_IND) == 4)
// 				{
// 					if ((cursor->encoding_byte >> (6 - i * 2) & 3) != 3)
// 						return (0);
// 				}
// 			}
// 			else if ((cursor->encoding_byte >> (6 - i * 2) & 3) != 0)
// 				return (0);
// 			i++;
// 		}
// 		return (1);
// 	}
// 	amount_args = op_tab[arena[cursor->position] - 1].amount_args;
// 	return (1);
// }