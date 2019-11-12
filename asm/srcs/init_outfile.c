/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_outfile.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:25:06 by svoort         #+#    #+#                */
/*   Updated: 2019/11/12 16:37:55 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_file	change_extension(t_file in)
{
	t_file	out;

	out.filename = ft_strcdup(in.filename, '.');
	out.filename = ft_joinfree(out.filename, ".cor", 1);
	return (out);
}
