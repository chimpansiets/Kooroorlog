/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:59:21 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 14:36:17 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_players(t_vm *vm)
{
	t_player *current;

	current = vm->players;
	ft_printf("Total_players: %i\n", vm->total_players);
	while (current != NULL)
	{
		ft_printf("Player name: %s\n", current->name);
		ft_printf("Player ID: %i\n\n", current->id);
		current = current->next;
	}
}