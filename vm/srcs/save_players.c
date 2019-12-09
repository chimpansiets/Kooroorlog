/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_players.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 12:59:03 by avan-rei       #+#    #+#                */
/*   Updated: 2019/12/09 13:58:55 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int      check_id(char *id)
{
    if (ft_strlen(id) > 1 || id[0] < '1' || id[0] > '4')
		print_error(invalid_id);
    return (1);
}

static int 		check_flag(char *str, char flag)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] != flag && ft_strequ(str, "-dump") != 1)
			print_error(invalid_flag);
		i++;
	}
	return (1);
}

static void		find_n_flag(t_vm *vm, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strnequ(argv[i], "-n", 2) == 1 && check_flag(argv[i], 'n') == 1)
		{
            while (ft_strnequ(argv[i], "-n", 2) == 1 && check_flag(argv[i], 'n') == 1)
                i++;
            if (check_id(argv[i]))
			    lstadd_player(vm, &vm->players, lstnew_player(argv[i + 1], ft_atoi(argv[i])));
		}
		i++;
	}
}

static void		find_d_flag(t_vm *vm, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if ((ft_strnequ(argv[i], "-d", 2) == 1 || ft_strnequ(argv[i], "-dump", 5) == 1) && check_flag(argv[i], 'd') == 1)
		{
			while ((ft_strnequ(argv[i], "-d", 2) == 1 || ft_strnequ(argv[i], "-dump", 5) == 1) && check_flag(argv[i], 'd') == 1)
				i++;
			vm->dump_flag = ft_atoi(argv[i]);
			vm->flag = ft_strdup(argv[i - 1]);
		}
		i++;
	}
}

static int		id_is_free(t_vm *vm, int id)
{
    t_player *current;

    current = vm->players;
    while (current)
    {
        if (current->id == id)
            return (0);
		current = current->next;
    }
    return (1);
}

static void		check_players(t_vm *vm)
{
	t_player	*current;
	t_player	*check;

	current = vm->players;
	while (current != NULL)
	{
		check = vm->players;
		while (check != NULL)
		{
			if (current->id == check->id && ft_strequ(current->file_name, check->file_name) != 1) //dees naar name
				print_error(invalid_id);
			check = check->next;
		}
		if (current->id > vm->total_players)
			print_error(invalid_id);
		current = current->next;
	}
}

void			save_players(t_vm *vm, int argc, char **argv)
{
	int i;
    int id;

	i = 1;
    id = 1;
	find_n_flag(vm , argc, argv);
	find_d_flag(vm , argc, argv);
	while (i < argc)
	{
        if (ft_strnequ(argv[i], "-n", 2) == 1 || ft_strnequ(argv[i], "-d", 2) == 1 || ft_strnequ(argv[i], "-dump", 5) == 1)
        {
            while (ft_strnequ(argv[i], "-n", 2) == 1 || ft_strnequ(argv[i], "-d", 2) == 1 || ft_strnequ(argv[i], "-dump", 5) == 1)
                i++;
            i += 2;
            continue ;
        }
        while (id_is_free(vm, id) == 0)
			id++;
        lstadd_player(vm, &vm->players, lstnew_player(argv[i], id));
        i++;
	}
	check_players(vm);
}
