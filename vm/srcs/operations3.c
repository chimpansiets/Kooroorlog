/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:36:10 by svoort         #+#    #+#                */
/*   Updated: 2019/12/12 16:34:10 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	fork(t_vm *vm, t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	t_cursor	*new;
	int			write_value;

	new = cursor;
	write_value = get_value(cursor, arena, 1, VALUE);
	new->position = write_value % IDX_MOD % MEM_SIZE;
	lstadd_cursor(&(vm->cursors), new);
}

void	lld(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{

}

void	lldi(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{

}

void	lfork(t_vm *vm, t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	t_cursor *new;

	new = cursor;
	new->position = get_value(new, arena, 1, VALUE);
	lstadd_cursor(&(vm->cursors), new);
}

void	aff(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	char	write_value;

	write_value = (char)get_value(cursor, arena, 1, VALUE);
	ft_printf("%c", write_value);
}