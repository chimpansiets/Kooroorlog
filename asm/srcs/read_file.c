/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:05:19 by svoort         #+#    #+#                */
/*   Updated: 2019/11/01 10:55:06 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	read_file_content(t_file *in, char *filename)
{
	read(in->fd, in->file_buffer, 4096);
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
