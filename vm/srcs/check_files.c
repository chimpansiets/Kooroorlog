/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:28:03 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 13:32:54 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	check_file(char *file_name)
{
	open(file_name,);
}

void	check_files(t_vm *vm)
{
	t_player *current;

	current = vm->players;
	while (current != NULL)
	{
		check_file(current->file_name);
		current = current->next;
	}
}