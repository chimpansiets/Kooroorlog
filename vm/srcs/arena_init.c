/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arena_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 13:57:08 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 14:14:10 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		arena_initialization(t_vm *vm)
{
	vm->arena[0] = 'a';
	ft_printf("%c\n", vm->arena[0]);
	vm->arena[0] = 'b';
	ft_printf("%c\n", vm->arena[0]);
}
