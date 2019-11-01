/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   component.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:04:01 by svoort         #+#    #+#                */
/*   Updated: 2019/11/01 11:28:09 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token	is_component(char *buffer, int index)
{
	if (is_separator(buffer, index))
		return (separator);
	else if (is_direct_label(buffer, index))
		return (direct_label);
	else if (is_label(buffer, index))
		return (label);
	else if (is_register(buffer, index))
		return (reg);
	else if (is_direct(buffer, index))
		return (direct_val);
	else if (is_instruction(buffer, index))
		return (instruction);
	else if (is_comment(buffer, index))
		return (comment);
	else
		return (none);
}

void	create_component(t_file *in, t_component components[2048], int *index)
{
	t_component	component;
	t_token		type;
	char		*str;

	if ((type = is_component(in->file_buffer, *index)) != none)
	{
		init_component(type, &component, in->file_buffer, *index);
	}
	else
		print_error(lexical_error, Err, ft_itoa(index));
	(*index) += ft_search_next_component(in->file_buffer, *index);
}
