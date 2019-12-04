/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstnew_cursor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:13:49 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 16:20:54 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_cursor	*lstnew_cursor(t_player *player)
{
	t_cursor *new;

	new = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	if (new == NULL)
		print_error(malloc_error);
	new->id = player->id;
	new->carry = 0;
	new->opcode = 0;
	new->last_live = 0;
	new->wait_cycles = 0;
	new->position = player->position;
	new->jump = 0;
	new->next = NULL;
	return (new);
}