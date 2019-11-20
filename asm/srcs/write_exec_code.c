/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_exec_code.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 14:38:46 by svoort         #+#    #+#                */
/*   Updated: 2019/11/20 18:07:45 by svoort        ########   odam.nl         */
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
	else if (arguments[1].type == direct_val || arguments[0].type == direct_label)
		codage_octal = codage_octal | 32;
	else if (arguments[1].type == indirect_val)
		codage_octal = codage_octal | 48;
	if (arguments[2].type == reg)
		codage_octal = codage_octal | 4;
	else if (arguments[2].type == direct_val || arguments[0].type == direct_label)
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

void			write_argument(int fd, t_argument argument)
{
	unsigned char	c;

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
	else if ()
}

void			write_instruction(int fd, t_component *component)
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
		write(fd, &(component->codage_octal), 1);
	}
	i = 0;
	while (i < 3)
	{
		write_argument(fd, component->arguments[i]);
		i++;
	}
}

void			write_champ_exec_code(t_file in, t_file out)
{
	t_component	*component;

	component = in.components;
	while (component->str != NULL)
	{
		if (component->type == instruction)
			write_instruction(out.fd, component);
		component++;
	}
}
