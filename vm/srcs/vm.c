/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:13:28 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 14:45:46 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_vm *vm;

	vm = (t_vm *)ft_memalloc(sizeof(t_vm));
	if (argc < 2)
		print_error(amount_args);
	save_players(vm, argc, argv);
	print_players(vm);
	//check_files(vm);
}