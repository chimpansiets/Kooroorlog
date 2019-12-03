/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstnew_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 11:35:32 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 17:20:40 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char		*ft_strdup_player(char *name)
{
	int i;

	i = ft_strlen(name) - 1;
	if (name[i - 3] != '.' || name[i - 2] != 'c' ||
		name[i - 1] != 'o' || name[i] != 'r')
		print_error(invalid_player_file);
	return(ft_strndup(name, i - 3));
}

t_player	*lstnew_player(char *name, int id)
{
	t_player *new;

	new = (t_player *)ft_memalloc(sizeof(t_player));
	if (new == NULL)
		print_error(malloc_error);
	if (id > MAX_PLAYERS)
		print_error(too_many_players);
	new->name = ft_strdup_player(name);
	new->file_name = ft_strdup(name);
	new->id = id;
	new->position = 0;
	new->comment = NULL;
	new->ex_code_size = CHAMP_MAX_SIZE;
	new->ex_code = 0;
	new->next = NULL;
	return (new);
}