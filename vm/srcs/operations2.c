/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:36:06 by svoort         #+#    #+#                */
/*   Updated: 2019/12/20 14:54:37 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sub(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	char	registry_nb;
	int		value1;
	int		value2;
	int		write_value;

	value1 = reverse_bytes(get_value(cursor, arena, 1, TRUNCATE_UNDEFINED));
	value2 = reverse_bytes(get_value(cursor, arena, 2, TRUNCATE_UNDEFINED));
	write_value = value1 - value2;
	registry_nb = arena[(cursor->position + cursor->has_encoding_byte + cursor->argument_position[2]) % MEM_SIZE];
	if (registry_nb - 1 < 0 || registry_nb - 1 > 15)
		ft_printf("sub ruk: %i", registry_nb);
	cursor->registries[registry_nb - 1] = reverse_bytes(write_value);
	set_carry(cursor, write_value);
}

void	and_or_xor(t_cursor *cursor, uint8_t arena[MEM_SIZE], int bitwise)
{
	int 	value1;
	int		value2;
	char	registry_nb;
	int		write_value;

	//ft_printf("ando\n");
	value1 = get_value(cursor, arena, 1, TRUNCATE);
	value2 = get_value(cursor, arena, 2, TRUNCATE);
	if (bitwise == AND)
		write_value = value1 & value2;
	else if (bitwise == OR)
		write_value = value1 | value2;
	else if (bitwise == XOR)
		write_value = value1 ^ value2;
	registry_nb = arena[(cursor->position + cursor->has_encoding_byte + cursor->argument_position[2]) % MEM_SIZE];
	if (registry_nb - 1 < 0 || registry_nb - 1 > 15)
		ft_printf("and ruk: %i", registry_nb);
	cursor->registries[registry_nb - 1] = write_value;
	set_carry(cursor, write_value);
}

void	zjmp(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	short	jompo_value;
	short	temp_value;

	temp_value = get_value(cursor, arena, 1, TRUNCATE_UNDEFINED);
	jompo_value = reverse_2bytes(temp_value);
	if (cursor->carry == 0)
		return ;
	if (jompo_value < 0)
	{
		if ((cursor->position + (jompo_value % -(IDX_MOD))) < 0)
			cursor->position = (cursor->position + (jompo_value % -(IDX_MOD))) % -(MEM_SIZE);
		else
			cursor->position = (cursor->position + (jompo_value % -(IDX_MOD))) % MEM_SIZE;
	}
	else
	{
		if ((cursor->position + (jompo_value % IDX_MOD)) < 0)
			cursor->position = (cursor->position + (jompo_value % IDX_MOD)) % -(MEM_SIZE);
		else
			cursor->position = (cursor->position + (jompo_value % IDX_MOD)) % MEM_SIZE;
	}
}

void	ldi(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		value1;
	int		value2;
	int		offset;
	int		to_store;
	int		registry_nb;

	if (cursor->type_arguments[0] == T_IND || cursor->type_arguments[0] == T_REG)
		value1 = reverse_bytes(get_value(cursor, arena, 1, NO_TRUNCATE));
	else
		value1 = reverse_2bytes((short)get_value(cursor, arena, 1, NO_TRUNCATE));
	if (cursor->type_arguments[1] == T_REG)
		value2 = reverse_bytes(get_value(cursor, arena, 2, TRUNCATE_UNDEFINED));
	else
		value2 = reverse_2bytes((short)get_value(cursor, arena, 2, TRUNCATE_UNDEFINED));
	registry_nb = arena[(cursor->position + cursor->has_encoding_byte + cursor->argument_position[2]) % MEM_SIZE];
	if ((value1 + value2) < 0)
		offset = (value1 + value2) % -(IDX_MOD);
	else
		offset = (value1 + value2) % IDX_MOD;
	if (cursor->position + offset < 0)
		to_store = *(int *)&arena[cursor->position + offset % -(MEM_SIZE)];
	else
		to_store = *(int *)&arena[cursor->position + offset % MEM_SIZE];
	if (registry_nb - 1 < 0 || registry_nb - 1 > 15)
		ft_printf("ldi ruk: %i", registry_nb);
	cursor->registries[registry_nb - 1] = to_store;
}

void	sti(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		write_value;
	int		value2;
	int		value3;
	int		position;

	write_value = get_value(cursor, arena, 1, TRUNCATE_UNDEFINED);
	if (cursor->type_arguments[1] == T_IND || cursor->type_arguments[1] == T_REG)
		value2 = reverse_bytes(get_value(cursor, arena, 2, NO_TRUNCATE));
	else
		value2 = reverse_2bytes(get_value(cursor, arena, 2, NO_TRUNCATE));
	if (cursor->type_arguments[2] == T_REG)
		value3 = reverse_bytes(get_value(cursor, arena, 3, NO_TRUNCATE));
	else
		value3 = reverse_2bytes(get_value(cursor, arena, 3, NO_TRUNCATE));
	if ((value2 + value3) < 0)
		position = cursor->position + ((value2 + value3) % -(IDX_MOD));
	else
		position = cursor->position + ((value2 + value3) % IDX_MOD);
	if (position < 0)
		ft_memcpy_corewar(arena, position % -(MEM_SIZE), &write_value, 4);
	else
		ft_memcpy_corewar(arena, position % MEM_SIZE, &write_value, 4);
}
