/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 14:12:10 by svoort         #+#    #+#                */
/*   Updated: 2019/11/21 12:27:04 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			g_verbose = DEBUG_LEVEL_COMP;
char			print_buffer = DEBUG_LEVEL_NONE;

int		its_morphin_time(char *file_name)
{
	t_file	in;
	t_file	out;

	check_and_read_file_content(&in, file_name);
	out = change_extension(in);
	out.fd = open(out.filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write_magic_to_file(in, out);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		print_error(amount_args, Err, argv[0]);
	else
		return (its_morphin_time(argv[argc - 1]));
	return (0);
}
