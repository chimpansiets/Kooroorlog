/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:13:26 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/05 16:16:10 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	move_cursor_to_next_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{

}

void	move_cursor_to_next_byte(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	cursor->position = (cursor->position + 1) % MEM_SIZE;
}