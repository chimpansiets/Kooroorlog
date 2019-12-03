/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_inits.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:59:30 by svoort         #+#    #+#                */
/*   Updated: 2019/12/03 17:22:04 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_champion_name(t_player *player)
{
	player->champ_name = ft_memalloc(sizeof(char) * PROG_NAME_LENGTH);
	read(player->fd, player->champ_name, PROG_NAME_LENGTH);
}
