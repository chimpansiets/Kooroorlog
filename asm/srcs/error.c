/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 14:35:31 by svoort         #+#    #+#                */
/*   Updated: 2019/11/06 10:50:36 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		amount_args_error(char *error_str)
{
	ft_putstr_fd("Error: no argument was given\n", 2);
	ft_printf("Got '%s' expected './asm [example_file.s]'\n", error_str);
}

static void		file_not_found_error(char *error_str)
{
	ft_putstr_fd("Error: file not found\n", 2);
	ft_printf("Got './asm %s'\n", error_str);
}

static void		check_errors(t_error type, char *error_str)
{
	if (type == amount_args)
		amount_args_error(error_str);
	else if (type == file_not_found)
		file_not_found_error(error_str);
	else if (type == lexical_error)
		ft_printf("Lexical error at index %s\n", error_str);
	else if (type == syntax)
		ft_printf("Syntax error at index %s\n", error_str);
	else if (type == name_missing)
		ft_putstr_fd("Error: champ name missing.", 2);
	else if (type == comment_missing)
		ft_putstr_fd("Error: champ comment missing.", 2);
}

int				print_error(t_error type, t_severity severity, char *error_str)
{
	if (severity == Err)
		check_errors(type, error_str);
	exit(1);
	return (1);
	// else if (severity == Warn)
	// 	check_warnings(type, error_str, expected);
}
