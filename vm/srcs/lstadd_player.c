/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstadd_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 11:32:52 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 14:49:46 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lstadd_player(t_vm *vm, t_player **head, t_player *new)
{
	t_player	*current;

	new->next = *head;
	*head = new;
	vm->total_players++;
}
