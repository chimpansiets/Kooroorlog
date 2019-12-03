/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:16:54 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 14:25:09 by avan-rei      ########   odam.nl         */
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
	else if (type == too_many_players)
		ft_putstr_fd("Error: Too many players.\n", 2);
	else if (type == malloc_error)
		ft_putstr_fd("Malloc Error.\n", 2);
}

void		print_error(t_error type)
{
	errors(type);
	exit(1);
}