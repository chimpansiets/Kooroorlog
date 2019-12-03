/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:28:03 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 14:50:07 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_file(char *file_name)
{
	int		fd;
	
	fd = open(file_name, O_RDONLY);
	check_magic_header(fd);
}

void	check_files(t_vm *vm)
{
	t_player *current;

	current = vm->players;
	while (current != NULL)
	{
		read_file(current->file_name);
		// check_file(current->file_name);
		current = current->next;
	}
}
