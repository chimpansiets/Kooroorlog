/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   component_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:26:34 by svoort         #+#    #+#                */
/*   Updated: 2019/11/01 11:37:32 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_separator(char *buffer, int index)
{
	if (buffer[index] == ',')
		return (1);
	else
		return (0);
}

int		is_direct_label(char *buffer, int index)
{
	if (buffer[index] == '%' && buffer[index + 1] == ':')
	{
		/* 
		** if (label_exists()), for now it will just return okay.
		** maybe it is better to check this later than here...
		*/
	}	
}
