/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_machine.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 15:35:52 by svoort         #+#    #+#                */
/*   Updated: 2019/11/12 12:14:44 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_state(int *state)
{
	*state = 127;
}

void	change_state(int *state, t_token type)
{
	if (type == label)
		*state = 127;
	else if (type == instruction)
		instruction_state(state);
	else if (type == reg)
		reg_state(state);
	else if (type == separator)
		separator_state(state);
	else if (type == direct_label)
		direct_label_state(state);
	else if (type == direct_val)
		direct_val_state(state);
	else if (type == indirect_val)
		indirect_val_state(state);
}

void	is_valid_type(int state, t_token type)
{
	if (type == label && )
		
}
