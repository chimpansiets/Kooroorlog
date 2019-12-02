/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_exec_code.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 14:38:46 by svoort         #+#    #+#                */
/*   Updated: 2019/12/02 15:36:00 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				get_instruction_index(char *buf)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strnequ(buf, instructions[i], ft_strlen(instructions[i])))
			return (i);
		i++;
	}
	return (-1);
}

unsigned char	get_codage_octal(t_argument *arguments)
{
	int		codage_octal;

	codage_octal = 0;
	if (arguments[0].type == reg)
		codage_octal = codage_octal | 64;
	else if (arguments[0].type == direct_val || arguments[0].type == direct_label)
		codage_octal = codage_octal | 128;
	else if (arguments[0]. type == indirect_val)
		codage_octal = codage_octal | 192;
	if (arguments[1].type == reg)
		codage_octal = codage_octal | 16;
	else if (arguments[1].type == direct_val || arguments[1].type == direct_label)
		codage_octal = codage_octal | 32;
	else if (arguments[1].type == indirect_val)
		codage_octal = codage_octal | 48;
	if (arguments[2].type == reg)
		codage_octal = codage_octal | 4;
	else if (arguments[2].type == direct_val || arguments[1].type == direct_label)
		codage_octal = codage_octal | 8;
	else if (arguments[2].type == indirect_val)
		codage_octal = codage_octal | 12;
	return (codage_octal);
}

unsigned char	get_registry_number(char *buf)
{
	int		nb;

	nb = ft_atoi(&buf[1]);
	return ((char)nb);
}

// if there are duplicate instructions, it wont know the difference of which one to find.
int				calculate_distance_to_label(t_argument argument, t_component *curr_component, t_component *all_components, int instr_index)
{
	int		index;
	int		label_index;
	int		distance;
	int		one_found;

	index = 0;
	distance = 0;
	one_found = 0;
	while (all_components[index].str != NULL)
	{
		if (all_components[index].type == label)
		{
			if (ft_strnequ(all_components[index].str, ft_joinfree(&argument.str[2], ":", 0), ft_strlen(&argument.str[2]) + 1))
			{
				label_index = index;
				if (one_found == 0)
					one_found = 1;
				else if (one_found == 2)
					break ;
			}
		}
		else if (all_components[index].type == instruction)
		{
			if (instr_index == index)
			{
				if (one_found == 0)
					one_found = 2;
				else if (one_found == 1)
					break ;
			}
		}
		if (one_found == 1 && all_components[index].type == instruction)
			distance -= all_components[index].byte_size;
		else if (one_found == 2 && all_components[index].type == instruction)
		{
			ft_printf("distance: %i += %i\n", distance, all_components[index].byte_size);
			distance += all_components[index].byte_size;
		}
		index++;
	}
	return (distance);
}

void			write_argument(int fd, t_argument argument, t_component *curr_component, t_component *all_components, int index)
{
	unsigned char	c;
	int				distance;

	if (argument.type == reg)
	{
		c = get_registry_number(argument.str);
		write(fd, &c, 1);
	}
	else if (argument.type == direct_val)
	{
		if (argument.byte_size == 4)
			write_reverse_int(fd, ft_atoi_b(&argument.str[1]));
		else
			write_reverse_2bytes(fd, ft_atoi_b(&argument.str[1]));
	}
	else if (argument.type == direct_label)
	{
		distance = calculate_distance_to_label(argument, curr_component, all_components, index);
		if (argument.byte_size == 4)
			write_reverse_int(fd, distance);
		else
			write_reverse_2bytes(fd, distance);
	}
	else if (argument.type == indirect_val)
		write_reverse_int(fd, ft_atoi(argument.str));
}

void			write_instruction(int fd, t_component *component, t_component *all_components, int index)
{
	int		i;
	int		instruction_index;

	instruction_index = get_instruction_index(component->str);
	if (instruction_index == -1)
		print_error(instr_not_found, Err, NULL);
	write(fd, &instruction_opcodes[instruction_index], 1);
	if (!ft_strequ(component->encoding_byte, "200"))
	{
		component->codage_octal = get_codage_octal(component->arguments);
		if (ft_strnequ("ldi", component->str, 3))
			ft_printf("encoding_byte: %s\n", component->encoding_byte);
		write(fd, &(component->codage_octal), 1);
	}
	i = 0;
	while (i < 3)
	{
		write_argument(fd, component->arguments[i], component, all_components, index);
		i++;
	}
}

void			write_champ_exec_code(t_file in, t_file out)
{
	t_component	*component;
	int			index;
	int			ctr;

	index = 0;
	component = in.components;
	ctr = 0;
	while (component->str != NULL)
	{
		if (component->type == instruction)
		{
			write_instruction(out.fd, component, in.components, index);
			ctr += 1;
		}
		component++;
		index++;
	}
}
