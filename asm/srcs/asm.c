/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 14:12:10 by svoort         #+#    #+#                */
/*   Updated: 2019/11/03 14:48:17 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			g_verbose = DEBUG_LEVEL_COMP;
char			print_buffer = DEBUG_LEVEL_NONE;

int		its_morphin_time(char *file_name)
{
	t_file	in;

	check_and_read_file_content(&in, file_name);
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
