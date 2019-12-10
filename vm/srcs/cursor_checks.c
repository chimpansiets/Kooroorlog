/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor_checks.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 11:28:37 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/10 12:17:45 by svoort        ########   odam.nl         */
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
	while (current != NULL)
	{
		tmp = current->next;
		if (current->last_live > vm->cycles_to_die)
			rm_cursor(&(vm->cursors), current);
		current = tmp;
	}
	print_cursor(vm);
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
		ft_printf("check_counter: %i\n", vm->check_counter);
		decrease_cycles_to_die(vm);
		vm->check_counter = 1;
	}
	vm->live_counter = 0;
	return (1);
}
