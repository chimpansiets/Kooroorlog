/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:36:10 by svoort         #+#    #+#                */
/*   Updated: 2019/12/18 17:32:09 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	registry_cpy(t_cursor *new, t_cursor *cpy)
{
	int		i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new->registries[i] = cpy->registries[i];
		i++;
	}
}

void	fork_corewar(t_vm *vm, t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	t_cursor	*new;
	int			offset;

	new = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	if (new == NULL)
		print_error(malloc_error);
	new->id = cursor->id;
	new->carry = cursor->carry;
	new->last_live = cursor->last_live;
	new->wait_cycles = -1;
	registry_cpy(new, cursor);
	offset = get_value(cursor, arena, 1, TRUNCATE_UNDEFINED);
	offset = reverse_2bytes(offset);
	if (offset < 0)
		new->position = (cursor->position + (offset % -(IDX_MOD))) % -(MEM_SIZE);
	else
		new->position = (cursor->position + (offset % IDX_MOD)) % MEM_SIZE;
	lstadd_cursor(&(vm->cursors), new);
}

void		lld(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		load_value;
	char	registry_nb;
	
	load_value = get_value(cursor, arena, 1, NO_TRUNCATE);
	set_carry(cursor, load_value);
	registry_nb = arena[(cursor->position + cursor->has_encoding_byte + cursor->argument_position[1]) % MEM_SIZE];
	if (registry_nb - 1 < 0)
		ft_printf("lld ruk: %i", registry_nb);
	cursor->registries[registry_nb - 1] = load_value;
}

void	lldi(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		value1;
	int		value2;
	int		offset;
	int		to_store;
	int		registry_nb;

	if (cursor->type_arguments[0] == T_DIR)
		value1 = reverse_2bytes(get_value(cursor, arena, 1, NO_TRUNCATE));
	else
		value1 = reverse_bytes(get_value(cursor, arena, 1, NO_TRUNCATE));
	if (cursor->type_arguments[1] == T_DIR)
		value2 = reverse_2bytes(get_value(cursor, arena, 2, TRUNCATE_UNDEFINED));
	else
		value2 = reverse_bytes(get_value(cursor, arena, 2, NO_TRUNCATE));
	registry_nb = arena[(cursor->position + cursor->has_encoding_byte + cursor->argument_position[1]) % MEM_SIZE];
	offset = (value1 + value2);
	if ((cursor->position + offset) < 0)
		to_store = *(int *)&arena[cursor->position + offset % -(MEM_SIZE)];
	else
		to_store = *(int *)&arena[cursor->position + offset % MEM_SIZE];
	if (registry_nb - 1 < 0)
		ft_printf("lldi ruk: %i", registry_nb);
	cursor->registries[registry_nb - 1] = to_store;
}

void	lfork(t_vm *vm, t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	t_cursor	*new;
	int			offset;

	new = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	if (new == NULL)
		print_error(malloc_error);
	new->id = cursor->id;
	new->carry = cursor->carry;
	new->last_live = cursor->last_live;
	new->wait_cycles = -1;
	registry_cpy(new, cursor);
	offset = get_value(cursor, arena, 1, TRUNCATE_UNDEFINED);
	offset = reverse_2bytes(offset);
	if ((cursor->position + offset) < 0)
		new->position = (cursor->position + offset) % -(MEM_SIZE);
	else
		new->position = (cursor->position + offset) % MEM_SIZE;
	lstadd_cursor(&(vm->cursors), new);
}

void	aff(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	char	write_value;

	write_value = (char)get_value(cursor, arena, 1, TRUNCATE_UNDEFINED);
	ft_printf("%c", write_value);
}