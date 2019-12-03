/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_players.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 12:59:03 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/03 13:32:19 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int 		check_n_flag(char *n_flag, char *id)
{
	int i;

	i = 1;
	while (n_flag[i] != '\0')
	{
		if (n_flag[i] != 'n')
			print_error(invalid_flag);
		i++;
	}
	if (ft_strlen(id > 1) || id[0] < '1' || id[0] > '4')
		print_error(invalid_id);
	return (1);
}

void	find_n_flag(t_vm *vm, int argc, char **argv)
{
	int i;

	i = 1;
	while (i <= argc)
	{
		if (ft_strnequ(argv[i], "-n", 2) == 1 && i + 1 < argc &&
        check_n_flag(argv[i], argv[i + 1]) == 1)
		{
			lstadd_player(&vm->players, lstnew_player(argv[i + 2], argv[i + 1]));
			i = 0;
		}
		i++;
	}
}

static int  id_is_free(t_vm *vm, int id)
{
    t_player *current;

    current = vm->players;
    while (current)
    {
        if (current->id == id)
            return (0);
    }
    return (1);
}

void	save_players(t_vm *vm, int argc, char **argv)
{
	int i;
    int id;

	i = 0;
    id = 1;
	find_n_flag(vm , argc, argv);
	while (i <= argc)
	{
        if (ft_strnequ(argv[i], "-n", 2) == 1)
        {
            i += 3;
            continue ;
        }

        i++;
	}
}