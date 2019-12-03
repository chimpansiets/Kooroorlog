/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:16:54 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 13:10:44 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		errors(t_error type)
{
	if (type == amount_args)
		ft_putstr_fd("Error: invalid amount of arguments.\n", 2);
	else if (type == invalid_flag)
		ft_putstr_fd("Error: invalid flag.\n", 2);
	else if (type == invalid_id)
		ft_putstr_fd("Error: invalid player id.\n", 2);
	else if (type == invalid_player_file)
		ft_putstr_fd("Error: invalid player file.\n", 2);
}

void		print_error(t_error type)
{
	errors(type);
	exit(1);
}