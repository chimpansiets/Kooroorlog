/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:05:19 by svoort         #+#    #+#                */
/*   Updated: 2019/11/02 16:48:13 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	read_file_content(t_file *in, char *filename)
{
	int		ret;
	char	buf[2];

	in->file_buffer = ft_memalloc(sizeof(char) * 4096);
	while ((ret = read(in->fd, buf, 1)) > 0)
	{
		buf[1] = '\0';
		ft_strcat(in->file_buffer, buf);
	}
	// in->file_buffer[ft_strlen(in->file_buffer)] = '\0';
	ft_printf("%s", in->file_buffer);
	in->filename = filename;
}

void	check_and_read_file_content(t_file *in, char *filename)
{
	in->fd = open(filename, O_RDONLY);

	if (in->fd < 0)
		print_error(file_not_found, Err, filename);
	read_file_content(in, filename);
	parse_components(in);
}
