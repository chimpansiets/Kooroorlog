/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_magic_to_file.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:48:04 by svoort         #+#    #+#                */
/*   Updated: 2019/11/19 17:55:43 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_magic_header(int fd)
{
	int				magic;
	unsigned char	*addr_magic;
	int				i;

	i = 4;
	magic = COREWAR_EXEC_MAGIC;
	addr_magic = (unsigned char*)&magic;
	while (i > 0)
	{
		write(fd, &addr_magic[i], 1);
		i--;
	}
}

t_component	*find_champ_name(t_component *components)
{
	t_component	*name_of_champ;

	name_of_champ = components;
	while (name_of_champ->str != NULL)
	{
		ft_printf("%s\n", name_of_champ->str);
		if (name_of_champ->type == champ_name)
			return (name_of_champ);
		name_of_champ++;
	}
	return (NULL);
}

void		write_champ_name(t_file in, t_file out)
{
	char		*name_of_champ;
	t_component	*name_component;
	int			extra_null_bytes;

	extra_null_bytes = 4;
	name_of_champ = ft_memalloc(sizeof(char) * PROG_NAME_LENGTH + extra_null_bytes);
	if (!(name_component = find_champ_name(in.components)))
		print_error(name_missing, Err, NULL);
	ft_strcat(name_of_champ, name_component->str);
	write(out.fd, name_of_champ, PROG_NAME_LENGTH + extra_null_bytes);
}

static int	get_instruction_size(t_component *component)
{
	int		size;
	int		i;

	i = 0;
	size = 1;
	while (i < 1)
	{
		size += component->arguments[i].byte_size;
		ft_printf("%i\n", component->arguments[i].byte_size);
		i++;
	}
	ft_printf("instruction: %s, size: %i\n", component->str, size);
	return (size);
}

static int	count_size(t_component *components)
{
	int	total_size;
	int	instr_size;

	total_size = 0;
	while (components->str != NULL)
	{
		if (components->type == instruction)
		{
			instr_size = get_instruction_size(components);
			total_size += instr_size;
		}
		components++;
	}
	return (total_size);
}

void		write_champ_exec_code_size(t_file in, t_file out)
{
	int				size;
	unsigned char	*addr_size;
	int				i;

	i = 4;
	size = count_size(in.components);
	ft_printf("%i\n", size);
	addr_size = (unsigned char*)&size;
	while (i > 0)
	{
		write(out.fd, &addr_size[i], 1);
		i--;
	}
}

void		write_magic_to_file(t_file in, t_file out)
{
	int			i;

	i = 0;
	write_magic_header(out.fd);
	write_champ_name(in, out);
	// while (i++ < 4)
	// 	write(out.fd, 0, 1);
	write_champ_exec_code_size(in, out);
	// write_champ_comment(in, out);
	// write_champ_exec_code(in, out);
	(void)in;
}
