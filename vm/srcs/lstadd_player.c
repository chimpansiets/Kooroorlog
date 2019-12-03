/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstadd_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 11:32:52 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 11:56:35 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lstadd_player(t_player **head, t_player *new)
{
	t_player	*current;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}