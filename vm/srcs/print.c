/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:59:21 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/18 17:40:34 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_cursor(t_vm *vm)
{
	t_cursor *current;

	current = vm->cursors;
	while (current != NULL)
	{
		ft_printf("\nCursor ID: %i\n", current->id);
		ft_printf("Opcode: %i\n", current->opcode);
		ft_printf("Last live: %i\n", current->last_live);
		ft_printf("Wait cycles: %i\n", current->wait_cycles);
		ft_printf("Position: %i\n\n", current->position);
		current = current->next;
	}
}

void	print_registries(t_cursor *cursor)
{
	int		reg_nb;

	reg_nb = 0;

	while (reg_nb < REG_NUMBER)
	{
		ft_printf("reg %i: %i\n", reg_nb, cursor->registries[reg_nb]);
		reg_nb++;
	}
}

void	print_players(t_vm *vm)
{
	t_player *current;

	current = vm->players;
	ft_printf("Total_players: %i\n\n", vm->total_players);
	while (current != NULL)
	{
		if (vm->dump_flag != -1)
			ft_printf("%s flag: %i\n", vm->flag, vm->dump_flag);
		ft_printf("Player name: %s\n", current->champ_name);
		ft_printf("Player ID: %i\n", current->id);
		ft_printf("Player code_size: %i\n", current->ex_code_size);
		ft_printf("Player position: %i\n\n", current->position);
		current = current->next;
	}
}

void	player_introduction(t_vm *vm)
{
	t_player	*current;
	int			id;

	current = vm->players;
	id = 1;
	ft_printf("Introducing contestants...\n");
	while (current != NULL && id <= vm->total_players)
	{
		if (current->id == id)
		{
			ft_printf("* Player %i, weighing %i bytes, %s\n", id, current->ex_code_size, current->champ_name); //current->comment nog erbij
			current = vm->players;
			id++;
		}
		else
			current = current->next;
	}
}