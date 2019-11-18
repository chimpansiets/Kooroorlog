/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_arguments.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:42:24 by svoort         #+#    #+#                */
/*   Updated: 2019/11/18 14:34:08 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_chmod_lookalike(t_component *component)
{
	char	*instruction;
	char	*encoding_byte;

	instruction = ft_strcdup(component->str, ' ');
	if (ft_strequ(instruction, "live") || ft_strequ(instruction, "zjmp") || \
	ft_strequ(instruction, "fork") || ft_strequ(instruction, "lfork"))
		encoding_byte = "200";
	else if (ft_strequ(instruction, "ld") || ft_strequ(instruction, "lld"))
		encoding_byte = "340";
	else if (ft_strequ(instruction, "st"))
		encoding_byte = "450";
	else if (ft_strequ(instruction, "add") || ft_strequ(instruction, "sub"))
		encoding_byte = "444";
	else if (ft_strequ(instruction, "and") || ft_strequ(instruction, "or") || \
		ft_strequ(instruction, "xor"))
		encoding_byte = "774";
	else if (ft_strequ(instruction, "ldi") || ft_strequ(instruction, "lldi"))
		encoding_byte = "764";
	else if (ft_strequ(instruction, "sti"))
		encoding_byte = "476";
	else if (ft_strequ(instruction, "aff"))
		encoding_byte = "400";
	
	component->encoding_byte = encoding_byte;
}

void	init_arguments(t_component *component, char *buffer, int index)
{
	init_chmod_lookalike(component);
	ft_printf("chmod: %s\n", component->encoding_byte);
}
