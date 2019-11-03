/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 09:26:16 by svoort         #+#    #+#                */
/*   Updated: 2019/11/03 14:52:56 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern char		g_verbose;

static void	print_components(t_component components[2048])
{
	int	i;

	i = 0;
	while (components[i].str != NULL)
	{
		ft_printf("%s\n", components[i].str);
		i++;
	}
}

void	parse_components(t_file *in)
{
	t_component	components[2048];
	int			index;

	index = 0;
	ft_bzero(components, sizeof(t_component) * 2048);
	while (in->file_buffer[index] != '\0')
		create_component(in, components, &index);
	if (g_verbose == 1)
		print_components(components);
	/*
	**	this will check if the executable code is in correct order,
	**	if valid arguments are given after instruction, etc.
	*/
	check_valid_executable_code(components);
}
