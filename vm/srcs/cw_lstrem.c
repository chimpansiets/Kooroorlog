/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cw_lstrem.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 12:59:18 by svoort         #+#    #+#                */
/*   Updated: 2019/12/05 13:04:24 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		rm_cursor(t_cursor **head, t_cursor *to_remove)
{
	t_cursor *current;
	t_cursor *temp;

	current = *head;
	if (to_remove == current)
	{
		*head = current->next;
		free(current);
		current = NULL;
		return ;
	}
	while (current->next && current->next != to_remove)
		current = current->next;
	if (current->next)
	{
		temp = current->next;
		current->next = current->next->next;
		free(temp);
		temp = NULL;
	}
	else
		dikke_error_a_bro_dingetje_bestaat_niet(1);
}
