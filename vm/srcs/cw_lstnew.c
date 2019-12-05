/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cw_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 12:55:30 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/05 16:30:16 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	*ft_strdup_player(char *name)
{
	int i;

	i = ft_strlen(name) - 1;
	if (name[i - 3] != '.' || name[i - 2] != 'c' ||
		name[i - 1] != 'o' || name[i] != 'r')
		print_error(invalid_player_file);
	return(ft_strdup(name));
}

t_player	*lstnew_player(char *name, int id)
{
	t_player *new;

	new = (t_player *)ft_memalloc(sizeof(t_player));
	if (new == NULL)
		print_error(malloc_error);
	if (id > MAX_PLAYERS)
		print_error(too_many_players);
	new->file_name = ft_strdup_player(name);
	new->id = id;
	new->ex_code_size = CHAMP_MAX_SIZE;
	return (new);
}

t_cursor	*lstnew_cursor(t_player *player)
{
	t_cursor *new;

	new = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	if (new == NULL)
		print_error(malloc_error);
	new->id = player->id;
	new->carry = 0;
	new->opcode = 0;
	new->last_live = 0;
	new->wait_cycles = 0;
	new->position = player->position;
	new->jump = 0;
	new->next = NULL;
	return (new);
}