/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_analysis.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 11:36:01 by svoort         #+#    #+#                */
/*   Updated: 2019/11/08 11:28:39 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// void	syntax_analysis(t_component *components)
// {
// 	int		i;
// 	char	state;

// 	i = 0;
// 	state = 127;
// 	while (components[i].str != NULL)
// 	{
// 		if (components[i].type != champ_name && components[i].type != champ_comment)
// 		{
// 			if (!is_valid_type(state, components[i].type))
// 				print_error(syntax, Err, ft_itoa(components[i].pos));
// 			change_state(&state, components[i].type);
// 		}
// 		i++;
// 	}
// }
