/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:36:10 by svoort         #+#    #+#                */
/*   Updated: 2019/12/16 16:19:17 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	fork_corewar(t_vm *vm, t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	t_cursor	*new;
	int			offset;

	new = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	if (new == NULL)
		print_error(malloc_error);
	new->id = cursor->id;
	offset = get_value(cursor, arena, 1, TRUNCATE_UNDEFINED);
	new->position = (cursor->position + (offset % IDX_MOD)) % MEM_SIZE;
	lstadd_cursor(&(vm->cursors), new);
}

void		lld(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		load_value;
	char	registry_nb;
	
	load_value = get_value(cursor, arena, 1, NO_TRUNCATE);
	set_carry(cursor, load_value);
	registry_nb = arena[cursor->position + cursor->has_encoding_byte + cursor->argument_position[1]];
	cursor->registries[registry_nb - 1] = load_value;
}

void	lldi(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	int		value1;
	int		value2;
	int		offset;
	int		to_store;
	int		registry_nb;

	value1 = reverse_bytes(get_value(cursor, arena, 1, NO_TRUNCATE));
	value2 = reverse_bytes(get_value(cursor, arena, 2, TRUNCATE_UNDEFINED));
	registry_nb = get_value(cursor, arena, 3, TRUNCATE_UNDEFINED);
	offset = (value1 + value2);
	to_store = *(int *)&arena[cursor->position + offset % MEM_SIZE];
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
	offset = get_value(cursor, arena, 1, TRUNCATE_UNDEFINED);
	new->position = cursor->position + offset % MEM_SIZE;
	lstadd_cursor(&(vm->cursors), new);
}

void	aff(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	char	write_value;

	write_value = (char)get_value(cursor, arena, 1, TRUNCATE_UNDEFINED);
	ft_printf("%c", write_value);
}