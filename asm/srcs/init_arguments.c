/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_arguments.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:42:24 by svoort         #+#    #+#                */
/*   Updated: 2019/11/19 17:51:26 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_chmod_lookalike(t_component *component)
{
	char	*instruction;
	char	*encoding_byte;

	instruction = ft_strcdup(component->str, ' ');
	if (ft_strequ(instruction, "live") || ft_strequ(instruction, "zjmp") || \
	ft_strequ(instruction, "fork") || ft_strequ(instruction, "lfork"))
		encoding_byte = "200";
	else if (ft_strequ(instruction, "ld") || ft_strequ(instruction, "lld"))
		encoding_byte = "340";
	else if (ft_strequ(instruction, "st"))
		encoding_byte = "450";
	else if (ft_strequ(instruction, "add") || ft_strequ(instruction, "sub"))
		encoding_byte = "444";
	else if (ft_strequ(instruction, "and") || ft_strequ(instruction, "or") || \
		ft_strequ(instruction, "xor"))
		encoding_byte = "774";
	else if (ft_strequ(instruction, "ldi") || ft_strequ(instruction, "lldi"))
		encoding_byte = "764";
	else if (ft_strequ(instruction, "sti"))
		encoding_byte = "476";
	else
		encoding_byte = "400";
	component->encoding_byte = encoding_byte;
}

static char	*get_nth_argument(char *buf, int n)
{
	int		i;
	int		ctr;
	int		start;

	i = 0;
	ctr = 0;
	while (buf[i] && buf[i] != '\n')
	{
		if (ft_isspace(buf[i]) || buf[i] == ',')
		{
			ctr++;
			while (ft_isspace(buf[i]) || buf[i] == ',')
				i++;
		}
		if (ctr == n)
			break ;
		i++;
	}
	start = i;
	while (buf[i] && !ft_isspace(buf[i]) && buf[i] != ',')
		i++;
	return (ft_strndup(&buf[start], i - start));
}

t_token		get_type_argument(char *argument_str)
{
	if (is_register(argument_str, 0))
		return (reg);
	else if (is_direct(argument_str, 0))
		return (direct_val);
	else if (is_direct_label(argument_str, 0))
		return (direct_label);
	else
		return (indirect_val);
}

size_t		get_byte_size(t_token type, int label_size)
{
	if (type == reg)
		return (1);
	else if (type == direct_val || type == direct_label)
		return (label_size);
	return (4);
}

t_argument	check_and_init_arg(t_component *component, int arg_number)
{
	t_argument	argument;

	argument.str = get_nth_argument(component->str, arg_number);
	argument.type = get_type_argument(argument.str);
	argument.byte_size = get_byte_size(argument.type, component->label_size);
	return (argument);
}

int			get_label_size(char *buf)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (ft_strnequ(buf, instructions[i], ft_strlen(instructions_label_2[i])))
			return (2);
		i++;
	}
	return (4);
}

void		init_arguments(t_component *component)
{
	int		label_size;

	label_size = get_label_size(component->str);
	component->label_size = label_size;
	init_chmod_lookalike(component);
	if (component->encoding_byte[0] != '0')
		component->arguments[0] = check_and_init_arg(component, 1);
	if (component->encoding_byte[1] != '0')
		component->arguments[1] = check_and_init_arg(component, 2);
	if (component->encoding_byte[2] != '0')
		component->arguments[2] = check_and_init_arg(component, 3);
}
