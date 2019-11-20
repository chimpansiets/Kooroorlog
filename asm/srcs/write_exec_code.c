/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_exec_code.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 14:38:46 by svoort         #+#    #+#                */
/*   Updated: 2019/11/20 15:29:45 by svoort        ########   odam.nl         */
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

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

void			write_instruction(int fd, t_component *component)
{
	int		instruction_index;

	instruction_index = get_instruction_index(component->str);
	if (instruction_index == -1)
		print_error(instr_not_found, Err, NULL);
	write(fd, &instruction_opcodes[instruction_index], 1);
	component->codage_octal = get_codage_octal(component->arguments);
	ft_printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(component->codage_octal));
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
