/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_inits.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:59:30 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 13:55:09 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_champion_name(t_player *player)
{
	player->champ_name = ft_memalloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	read(player->fd, player->champ_name, PROG_NAME_LENGTH);
	player->champ_name[PROG_NAME_LENGTH] = '\0';
}

void	read_champion_comment(t_player *player)
{
	player->champ_comment = ft_memalloc(sizeof(char) * COMMENT_LENGTH + 1);
	read(player->fd, player->champ_comment, COMMENT_LENGTH);
	player->champ_comment[COMMENT_LENGTH] = '\0';
}

void	read_exec_code(t_player *player)
{
	player->ex_code = (uint8_t *)ft_memalloc(sizeof(uint8_t) * player->ex_code_size);
	read(player->fd, player->ex_code, player->ex_code_size);
}
