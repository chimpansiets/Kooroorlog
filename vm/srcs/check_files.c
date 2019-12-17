/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:28:03 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/17 16:07:07 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_file(t_player *player)
{	
	player->fd = open(player->file_name, O_RDONLY);
	check_magic_header(player->fd);
	read_champion_name(player);
	check_null_bytes(player->fd);
	if (check_exec_code_size(player) == 0)
	{
		ft_printf("Error: File %s has too large a code (%i bytes > %i bytes)\n", player->file_name, player->ex_code_size, CHAMP_MAX_SIZE);
		exit(1);
	}
	read_champion_comment(player);
	check_null_bytes(player->fd);
	read_exec_code(player);
}

void	check_files(t_vm *vm)
{
	t_player *current;

	current = vm->players;
	while (current != NULL)
	{
		read_file(current);
		current = current->next;
	}
}
