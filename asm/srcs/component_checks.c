/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   component_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:26:34 by svoort         #+#    #+#                */
/*   Updated: 2019/11/06 11:12:23 by svoort        ########   odam.nl         */
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

int		is_indirect(char *buffer, int index)
{
	if (ft_is_int(&buffer[index]))
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
		if (ft_strnequ(&buffer[index], instructions[i], ft_strlen(instructions[i])))
			is_instruction = 1;
		i++;
	}
	return (is_instruction);
}

int		is_comment(char *buffer, int index)
{
	if (buffer[index] == '#')
		return (1);
	else
		return (0);
}

int		is_champ_name(char *buffer, int index)
{
	if (buffer[index] == '.' && ft_strnequ(&buffer[index + 1], "name", 4))
		return (1);
	else
		return (0);
}

int		is_champ_comment(char *buffer, int index)
{
	if (buffer[index] == '.' && ft_strnequ(&buffer[index + 1], "comment", 7))
		return (1);
	else
		return (0);
}
