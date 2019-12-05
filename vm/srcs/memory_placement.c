/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_placement.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:01:59 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 16:06:30 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	place_player_in_mem(t_vm *vm, t_player *player)
{
	int		i;

	i = 0;
	while (i < player->ex_code_size)
	{
		vm->arena[player->position + i] = player->ex_code[i];
		i++;
	}
}
