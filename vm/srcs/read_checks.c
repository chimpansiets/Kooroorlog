/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_checks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:57:03 by svoort         #+#    #+#                */
/*   Updated: 2019/12/03 14:49:26 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char	*write_reverse_int_dup(int value)
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

void	check_magic_header(int fd)
{
	unsigned char	file_header[4];
	unsigned char	*corewar_exec_header;
	int				corewar_exec_magic;

	read(fd, file_header, 4);
	
	corewar_exec_magic = COREWAR_EXEC_MAGIC;
	corewar_exec_header = write_reverse_int_dup(COREWAR_EXEC_MAGIC);
	ft_printf("file: %x %x %x %x\n", file_header[0], file_header[1], file_header[2], file_header[3]);
	ft_printf("corewar: %x %x %x %x\n", corewar_exec_header[0], corewar_exec_header[1], corewar_exec_header[2], corewar_exec_header[3]);
	if (ft_memcmp(file_header, corewar_exec_header, 4) == 0)
		ft_printf("*clicking noise* nice...\n");
	else
		ft_printf("fuuuuuu\n");
}
