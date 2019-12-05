/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:13:28 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/04 16:33:12 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_vm *vm;

	vm = (t_vm *)ft_memalloc(sizeof(t_vm));
	vm_init(vm);
	if (argc < 2)
		print_error(amount_args);
	save_players(vm, argc, argv);
	calc_position(vm);
	check_files(vm);
	print_players(vm);
	player_introduction(vm);
	arena_initialization(vm);
	the_battle(vm);
}
