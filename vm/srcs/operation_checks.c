/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 15:23:56 by svoort         #+#    #+#                */
/*   Updated: 2019/12/16 14:07:58 by svoort        ########   odam.nl         */
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
		if (cursor->has_encoding_byte)
		{
			if (T_REG & (cursor->encoding_byte >> (6 - (i * 2))) && ((2 & (cursor->encoding_byte >> (6 - (i * 2)))) == 0))
			{
				reg_number = arena[(cursor->position + cursor->has_encoding_byte + cursor->argument_position[i]) % MEM_SIZE];
				if (reg_number < 1 || REG_NUMBER < reg_number)
				{
					ft_printf("hier%i\n", reg_number);
					return (0);
				}
			}
		}
		else if (T_REG & op_tab[cursor->opcode - 1].type_args[i])
		{
			reg_number = arena[(cursor->position + cursor->has_encoding_byte + cursor->argument_position[i]) % MEM_SIZE];
			if (reg_number < 1 || REG_NUMBER < reg_number)
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
			if ((i >= op_tab[op_index].amount_args) || (op_tab[op_index].type_args[i] & T_IND) != T_IND)
				return (0);
			cursor->type_arguments[i] = T_IND;
		}
		else if ((encoding_byte & 2) == 2)
		{
			if ((i >= op_tab[op_index].amount_args) || (op_tab[op_index].type_args[i] & T_DIR) != T_DIR)
				return (0);
			cursor->type_arguments[i] = T_DIR;
		}
		else if ((encoding_byte & 1) == 1)
		{
			if ((i >= op_tab[op_index].amount_args) || (op_tab[op_index].type_args[i] & T_REG) != T_REG)
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
		if (!(bit_shift_gedoe(cursor, cursor->encoding_byte, arena[cursor->position] - 1)))
			return (0);
		cursor->has_encoding_byte = 1;
	}
	return (1);
}
