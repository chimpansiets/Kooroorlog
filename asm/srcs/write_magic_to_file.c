/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_magic_to_file.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:48:04 by svoort         #+#    #+#                */
/*   Updated: 2019/11/14 11:03:29 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_magic_header(int fd)
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

void	write_champ_name(t_file in, t_file out)
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

void	write_champ_exec_code_size(t_file in, t_file out)
{
	int		size;

	size = count_size();
}

void	write_magic_to_file(t_file in, t_file out)
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
