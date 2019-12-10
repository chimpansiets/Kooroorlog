/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cw_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 12:55:35 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/09 17:38:22 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lstadd_cursor(t_cursor **head, t_cursor *new)
{
	if (!(*head))
	{
		*head = new;
		return ;
	}
	new->next = *head;
	*head = new;
}

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