/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor_checks.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 11:28:37 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/09 15:15:34 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
	
static void		decrease_cycles_to_die(t_vm *vm)
{
	vm->cycles_to_die -= CYCLE_DELTA;
}

static int		check_dead_cursor(t_vm *vm)
{
	t_cursor	*current;
	t_cursor	*tmp;
	int			cursor;

	current = vm->cursors;
	if (current == NULL)
		return(0);
	while (current != NULL)
	{
		tmp = current->next;
		if (current->last_live > vm->cycles_to_die)
			rm_cursor(&(vm->cursors), current);
		current = tmp;
	}
	if (vm->cursors == NULL)
		return (0);
	return (1);
}

int				check(t_vm *vm)
{
	if (check_dead_cursor(vm) == 0)
		return (0);
	if (vm->live_counter >= NBR_LIVE)
	{
		decrease_cycles_to_die(vm);
		vm->check_counter = 1;
	}
	else if (vm->check_counter >= MAX_CHECKS)
	{
		decrease_cycles_to_die(vm);
		vm->check_counter = 1;
	}
	vm->live_counter = 0;
	return (1);
}
