/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:28:03 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/04 12:41:31 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_file(t_player *player)
{	
	player->fd = open(player->file_name, O_RDONLY);
	check_magic_header(player->fd);
	read_champion_name(player);
	check_null_bytes(player->fd);
	check_exec_code_size(player);
	// read_champion_comment(player);
	// check_null_bytes(fd);
}

void	check_files(t_vm *vm)
{
	t_player *current;

	current = vm->players;
	while (current != NULL)
	{
		read_file(current);
		// check_file(current->file_name);
		current = current->next;
	}
}
