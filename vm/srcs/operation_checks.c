/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 15:23:56 by svoort         #+#    #+#                */
/*   Updated: 2019/12/05 16:50:38 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern	t_op	op_tab[17];

int		is_valid_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	if (op_tab[cursor->opcode].has_encoding_byte == 1)
		return (1);
	else
		return (0);
}

int		validate_registry_numbers(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		i;
	int		reg_number;

	if (cursor->has_encoding_byte)
	{
		i = 0;
		while (i < op_tab[cursor->opcode - 1].amount_args)
		{
			if (T_REG & (cursor->encoding_byte >> (6 - (i * 2))))
			{
				reg_number = arena[(cursor->position + cursor->has_encoding_byte + i + 1) % MEM_SIZE]
				if (0 < reg_number && reg_number <= REG_NUMBER)
					return (1);
			}
			i++;
		}
	}
	else
	{
		
	}
}



validate_encoding_byte(t_cursor *cursor, uint8_t *arena)
{
	int amount_args;

	if (op_tab[arena[cursor->position]].has_encoding_byte)
	{
		cursor->encoding_byte = arena[(cursor->position + 1) % MEM_SIZE];
		return (1);
	}
	amount_args = op_tab[arena[cursor->position]].amount_args;
	if ((arena[(cursor->position + 1) % MEM_SIZE]
	{
		
	}
	return (1);
}