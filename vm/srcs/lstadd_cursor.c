/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstadd_cursor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:13:40 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 16:19:15 by svoort        ########   odam.nl         */
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