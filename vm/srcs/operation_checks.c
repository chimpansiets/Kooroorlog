/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 15:23:56 by svoort         #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/12/10 11:04:55 by svoort        ########   odam.nl         */
=======
/*   Updated: 2019/12/09 18:02:19 by avan-rei      ########   odam.nl         */
>>>>>>> 788eb71ed76fb75eb14313d78cc8ff7482b4451d
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
<<<<<<< HEAD
				if (1 <= reg_number && reg_number <= REG_NUMBER)
=======
				if (!(0 < reg_number && reg_number <= REG_NUMBER))
				{
					ft_printf("hier1");
>>>>>>> 788eb71ed76fb75eb14313d78cc8ff7482b4451d
					return (0);
				}
			}
		}
		else if (T_REG & op_tab[cursor->opcode - 1].type_args[i])
		{
			reg_number = arena[(cursor->position + cursor->has_encoding_byte + i + 1) % MEM_SIZE];
<<<<<<< HEAD
			if (1 <= reg_number && reg_number <= REG_NUMBER)
=======
			if (!(0 < reg_number && reg_number <= REG_NUMBER))
			{
				ft_printf("hier2");
>>>>>>> 788eb71ed76fb75eb14313d78cc8ff7482b4451d
				return (0);
			}
		}
		i++;
	}
	ft_printf("hier6");
	return (1);
}

static int	bit_shift_gedoe(int encoding_byte, char op_index)
{
	int i;

	i = 2;
	while (i >= 0)
	{
<<<<<<< HEAD
		encoding_byte = encoding_byte >> 2;
=======
		encoding_byte >>= 2;
>>>>>>> 788eb71ed76fb75eb14313d78cc8ff7482b4451d
		if ((encoding_byte & 3) == 3)
		{
			if ((op_tab[op_index].type_args[i] & 4) != 4)
				return (0);
		}
		else if (encoding_byte & 2)
		{
			if ((op_tab[op_index].type_args[i] & 2) != 2)
				return (0);
		}
		else if (encoding_byte & 1)
		{
			if ((op_tab[op_index].type_args[i] & 1) != 1)
				return (0);
		}
		else if (i < op_tab[op_index].amount_args)
			return (0);
		i--;
	}
	return (1);
}


int		validate_encoding_byte(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
<<<<<<< HEAD
	int	i;

	i = 2;
=======
>>>>>>> 788eb71ed76fb75eb14313d78cc8ff7482b4451d
	if (op_tab[arena[cursor->position] - 1].has_encoding_byte)
	{
		cursor->encoding_byte = arena[(cursor->position + 1) % MEM_SIZE];
		if (cursor->encoding_byte & 3)
<<<<<<< HEAD
			return (0);
		if (!bit_shift_gedoe(cursor->encoding_byte, arena[cursor->position % MEM_SIZE] - 1))
			return (0);
	}
=======
		{
			ft_printf("hier3");
			return (0);
		}
		if (bit_shift_gedoe(cursor->encoding_byte, arena[cursor->position - 1]) == 0)
		{
			ft_printf("hier4");
			return(0);
		}
	}
	ft_printf("hier5");
>>>>>>> 788eb71ed76fb75eb14313d78cc8ff7482b4451d
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