/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_exec_code.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 14:38:46 by svoort         #+#    #+#                */
/*   Updated: 2019/11/21 16:27:46 by svoort        ########   odam.nl         */
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

// needs fix
int				calculate_distance_to_label(t_argument argument, t_component *curr_component, t_component *all_components)
{
	int		index;
	int		label_index;
	int		instruction_index;
	int		distance;
	int		one_found;

	index = 0;
	distance = 0;
	one_found = 0;
	while (all_components[index].str != NULL)
	{
		if (all_components[index].type == label)
		{
			ft_printf("label_check: checking %s with %s\n", all_components[index].str, ft_joinfree(&argument.str[2], ":", 0));
			if (ft_strnequ(all_components[index].str, ft_joinfree(&argument.str[2], ":", 0), ft_strlen(&argument.str[2])))
			{
				label_index = index;
				if (one_found == 0)
					one_found = 1;
				else if (one_found == 2)
					break ;
				ft_printf("one_found: %i\n", one_found);
			}
		}
		else if (all_components[index].type == instruction)
		{
			ft_printf("comp_check: checking %s with %s\n", all_components[index].str, curr_component->str);
			if (ft_strequ(all_components[index].str, curr_component->str))
			{
				instruction_index = index;
				if (one_found == 0)
					one_found = 2;
				else if (one_found == 1)
					break ;
				ft_printf("one_found: %i\n", one_found);
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
	ft_printf("distance: %i\n", distance);
	return (distance);
}

void			write_argument(int fd, t_argument argument, t_component *curr_component, t_component *all_components)
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
			write_reverse_int(fd, ft_atoi(&argument.str[1]));
		else
			write_reverse_2bytes(fd, (uint16_t)ft_atoi(&argument.str[1]));
	}
	else if (argument.type == direct_label)
	{
		distance = calculate_distance_to_label(argument, curr_component, all_components);
		ft_printf("distance from %s to %s: %i\n", curr_component->str, argument.str, distance);
		if (argument.byte_size == 4)
			write_reverse_int(fd, distance);
		else
			write_reverse_2bytes(fd, (uint16_t)distance);
	}
	else if (argument.type == indirect_val)
		write_reverse_int(fd, ft_atoi(argument.str));
}

void			write_instruction(int fd, t_component *component, t_component *all_components)
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
		ft_printf("codage_octal: %i\n", component->codage_octal);
		write(fd, &(component->codage_octal), 1);
	}
	i = 0;
	while (i < 3)
	{
		write_argument(fd, component->arguments[i], component, all_components);
		i++;
	}
}

void			write_champ_exec_code(t_file in, t_file out)
{
	t_component	*component;
	int			ctr;

	ctr = 0;
	component = in.components;
	while (component->str != NULL)
	{
		if (component->type == instruction)
		{
			write_instruction(out.fd, component, in.components);
			ctr++;
			if (ctr == 2)
				exit(1);
		}
		component++;
	}
}
