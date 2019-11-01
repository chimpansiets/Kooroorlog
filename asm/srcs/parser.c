/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 09:26:16 by svoort         #+#    #+#                */
/*   Updated: 2019/11/01 11:04:12 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_components(t_file *in)
{
	t_component	components[2048];
	int			index;

	index = 0;
	while (in->file_buffer[index] != '\0')
	{
		create_component(in, components, &index);
		ft_printf("%i\n", components[0].pos);
	}
}
