/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   component.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:04:01 by svoort         #+#    #+#                */
/*   Updated: 2019/11/27 12:27:53 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token	is_component(char *buffer, int index)
{
	if (is_separator(buffer, index))
		return (separator);
	else if (is_label(buffer, index))
		return (label);
	else if (is_instruction(buffer, index))
		return (instruction);
	else if (is_comment(buffer, index))
		return (comment);
	else if (is_champ_name(buffer, index))
		return (champ_name);
	else if (is_champ_comment(buffer, index))
		return (champ_comment);
	else
		return (none);
}

static int		ft_search_next_component(char *buffer, int index)
{
	int		i;

	i = index;
	while (buffer[i] && (buffer[i] == ' ' || \
			buffer[i] == '\t' || buffer[i] == '\n'))
		i++;
	return (i - index);
}

static void		add_to_components(t_component components[2048], t_component component)
{
	static int		curr_index = 0;
	t_component		new;

	new.type = component.type;
	new.str = component.str;
	new.pos = component.pos;
	new.len = component.len;
	new.arguments[0] = component.arguments[0];
	new.arguments[1] = component.arguments[1];
	new.arguments[2] = component.arguments[2];
	new.label_size = component.label_size;
	new.encoding_byte = component.encoding_byte;
	new.byte_size = component.byte_size;
	new.codage_octal = 0;
	components[curr_index] = new;
	curr_index++;
}

void	create_component(t_file *in, t_component components[2048], int *index)
{
	t_component	component;
	t_token		type;

	(*index) += ft_search_next_component(in->file_buffer, *index);
	if (in->file_buffer[*index] == '\0')
		return ;
	if ((type = is_component(in->file_buffer, *index)) != none)
	{
		init_component(type, &component, in->file_buffer, *index);
		add_to_components(components, component);
		if (type == champ_name && ++(*index))
			in->has_name = 1;
		else if (type == champ_comment && ++(*index))
			in->has_comment = 1;
	}
	else
		print_error(lexical_error, Err, ft_itoa(*index));
	(*index) += component.len;
}
