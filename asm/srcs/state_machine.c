/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_machine.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 15:35:52 by svoort         #+#    #+#                */
/*   Updated: 2019/11/06 15:53:18 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	change_state(int *state, t_token type)
{
	if (type == label)
		label_state();
	else if (type == instruction)
		instruction_state();
	else if (type == reg)
		reg_state();
	else if (type == separator)
		separator_state();
	else if (type == direct_label)
		direct_label_state();
	else if (type == direct_val)
		direct_val_state();
	else if (type == indirect_val)
		indirect_val_state();
	else if (type == comment)
		comment_state();
}
