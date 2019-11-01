/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 14:12:10 by svoort         #+#    #+#                */
/*   Updated: 2019/11/01 10:54:42 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		power_rangers_assemble(char *file_name)
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
		return (power_rangers_assemble(argv[argc - 1]));
	return (0);
}
