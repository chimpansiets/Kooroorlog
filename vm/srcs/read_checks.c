/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_checks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:57:03 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 13:47:02 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static unsigned char	*write_reverse_int_dup(int value)
{
	unsigned char	*buf;
	unsigned char	*addr_value;
	int				i;
	int				buf_index;

	buf = (unsigned char *)ft_memalloc(sizeof(char) * 5);
	i = 3;
	buf_index = 0;
	addr_value = (unsigned char*)&value;
	while (i > -1)
	{
		buf[buf_index] = addr_value[i];
		buf_index++;
		i--;
	}
	buf[buf_index] = '\0';
	return (buf);
}

static unsigned char	*write_reverse_buffer_dup(unsigned char *input)
{
	unsigned char	*buf;
	int				i;
	int				buf_index;

	buf = (unsigned char *)ft_memalloc(sizeof(char) * 5);
	i = 3;
	buf_index = 0;
	while (i > -1)
	{
		buf[buf_index] = input[i];
		buf_index++;
		i--;
	}
	buf[buf_index] = '\0';
	return (buf);
}

int						check_magic_header(int fd)
{
	unsigned char	file_header[5];
	unsigned char	*corewar_exec_header;
	int				corewar_exec_magic;

	read(fd, file_header, 4);
	file_header[4] = '\0';
	
	corewar_exec_magic = COREWAR_EXEC_MAGIC;
	corewar_exec_header = write_reverse_int_dup(COREWAR_EXEC_MAGIC);
	if (ft_memcmp(file_header, corewar_exec_header, 4) == 0)
		return (1);
	else
		return (0);
}

int						check_null_bytes(int fd)
{
	unsigned char	buf[5];
	int				i;

	read(fd, buf, 4);
	buf[4] = '\0';
	i = 0;
	while (i < 4)
	{
		if (buf[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int						check_exec_code_size(t_player *player)
{
	unsigned char	buf[5];
	unsigned char	*exec_code_size;
	int				*size;

	read(player->fd, buf, 4);
	buf[4] = '\0';
	player->ex_code_size = 0;
	exec_code_size = write_reverse_buffer_dup(buf);
	size = (int *)ft_memalloc(sizeof(int) + 1);
	ft_memcpy(size, exec_code_size, 5);
	player->ex_code_size = *exec_code_size;
	if (player->ex_code_size > CHAMP_MAX_SIZE)
		return (0);
	return (1);
}
