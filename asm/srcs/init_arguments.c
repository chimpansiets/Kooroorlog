/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_arguments.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:42:24 by svoort         #+#    #+#                */
/*   Updated: 2019/12/02 15:11:29 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_chmod_lookalike(t_component *component)
{
	char	*instruction;
	char	*encoding_byte;

	encoding_byte = NULL;
	instruction = ft_strtrim(component->str);
	if (ft_strnequ(instruction, "live", 4) || ft_strnequ(instruction, "zjmp", 4) || \
	ft_strnequ(instruction, "fork", 4) || ft_strnequ(instruction, "lfork", 5))
		encoding_byte = "200";
	else if (ft_strnequ(instruction, "ldi", 3) || ft_strnequ(instruction, "lldi", 4))
		encoding_byte = "764";
	else if (ft_strnequ(instruction, "ld", 2) || ft_strnequ(instruction, "lld", 3))
		encoding_byte = "340";
	else if (ft_strnequ(instruction, "sti", 3))
		encoding_byte = "476";
	else if (ft_strnequ(instruction, "st", 2))
		encoding_byte = "450";
	else if (ft_strnequ(instruction, "add", 3) || ft_strnequ(instruction, "sub", 3))
		encoding_byte = "444";
	else if (ft_strnequ(instruction, "and", 3) || ft_strnequ(instruction, "or", 2) || \
		ft_strnequ(instruction, "xor", 3))
		encoding_byte = "774";
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
	else if (is_direct_label(argument_str, 0))
		return (direct_label);
	else if (is_direct(argument_str, 0))
		return (direct_val);
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

static int	is_ld_or_st(char *buf)
{
	char	*str;

	str = ft_strtrim(buf);
	if (ft_strlen(str) > 2)
	{
		if (str[0] == 's' && str[1] == 't' && str[2] != 'i')
			return (1);
		if (str[0] == 'l' && str[1] == 'd' && str[2] != 'i')
			return (1);
	}
	return (0);
}

int			get_label_size(char *buf)
{
	int		i;

	i = 0;
	if (is_ld_or_st(buf))
		return (4);
	while (i < 6)
	{
		if (ft_strnequ(buf, instructions_label_2[i], ft_strlen(instructions_label_2[i])))
			return (2);
		i++;
	}
	return (4);
}

// Still need to check which argument are allowed with encoding byte, not just if '0'.
void		init_arguments(t_component *component)
{
	ft_bzero(component->arguments, sizeof(t_argument) * 3);
	component->label_size = get_label_size(component->str);
	init_chmod_lookalike(component);
	if (component->encoding_byte[0] != '0')
		component->arguments[0] = check_and_init_arg(component, 1);
	if (component->encoding_byte[1] != '0')
		component->arguments[1] = check_and_init_arg(component, 2);
	if (component->encoding_byte[2] != '0')
		component->arguments[2] = check_and_init_arg(component, 3);
	component->byte_size = 1 + component->arguments[0].byte_size + component->arguments[1].byte_size + component->arguments[2].byte_size;
	if (!ft_strequ(component->encoding_byte, "200"))
		component->byte_size++;
}
