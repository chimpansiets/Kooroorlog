/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstadd_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 11:32:52 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 17:20:26 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lstadd_player(t_vm *vm, t_player **head, t_player *new)
{
	if (!(*head))
	{
		*head = new;
		vm->total_players++;
		return ;
	}
	new->next = *head;
	*head = new;
	vm->total_players++;
}
