/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   component_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:26:34 by svoort         #+#    #+#                */
/*   Updated: 2019/11/01 16:59:54 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_separator(char *buffer, int index)
{
	if (buffer[index] == ',')
		return (1);
	else
		return (0);
}

int		is_direct_label(char *buffer, int index)
{
	if (buffer[index] == '%' && buffer[index + 1] == ':')
	{
		/* 
		** if (label_exists()), for now it will just return okay.
		** maybe it is better to check this later than here...
		*/
		return (1);
	}
	return (0);
}

int		is_label(char *buffer, int index)
{
	int		i;

	i = index;
	while (buffer[i] != LABEL_CHAR && buffer[i])
	{
		if (ft_strchr(LABEL_CHARS, buffer[i]) == NULL)
			return (0);
		i++;
	}
	if (buffer[i] == LABEL_CHAR && i > index)
		return (1);
	else
		return (0);
}

int		is_register(char *buffer, int index)
{
	if (buffer[index] == 'r')
		return (1);
	else
		return (0);
}

int		is_direct(char *buffer, int index)
{
	if (buffer[index] == '%')
		return (1);
	else
		return (0);
}

int		is_instruction(char *buffer, int index)
{
	int		i;
	int		is_instruction;

	i = 0;
	is_instruction = 0;
	while (i < 15)
	{
		if (ft_strnstr(&buffer[index], instructions[i], 5))
			is_instruction = 1;
		i++;
	}
	return (is_instruction);
}
