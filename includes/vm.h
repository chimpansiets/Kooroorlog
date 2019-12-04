/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 14:14:01 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 14:29:02 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# define MAX_PLAYERS 4

# include "libft.h"
# include <stdio.h> // remove this
# include <limits.h>
# include <errno.h>
# include <stdbool.h>
# include "libft.h"
# include "op.h"

typedef enum		e_error {
	amount_args,
	invalid_flag,
	invalid_id,
	invalid_player_file,
	too_many_players,
	malloc_error,
	ex_code_too_big,
}					t_error;

typedef struct		e_player {
	int				id;
	int				fd;
	char			*name;
	char			*champ_name;
	char			*champ_comment;
	char			*file_name;
	int				ex_code_size;
	uint8_t			*ex_code;
	int				position;
	struct e_player	*next;
}					t_player;

typedef struct		e_vm {
	int				total_players;
	uint8_t			arena[MEM_SIZE];
	t_player		*players;
}					t_vm;

typedef struct		e_cursor
{
	int				id;
	char			carry;
	int				opcode;
	int				last_live;
	int				wait_cycles;
	int				position;
	int				jump;
	char			registries[REG_NUMBER];
}					t_cursor;


void				print_error(t_error type);
void				print_players(t_vm *vm);

void				lstadd_player(t_vm *vm, t_player **head, t_player *new);
t_player			*lstnew_player(char *name, int id);

void				save_players(t_vm *vm, int argc, char **argv);
void				calc_position(t_vm *vm);
void				check_files(t_vm *vm);
void				player_introduction(t_vm *vm);

/*
**	check_files.c
*/

void				read_file(t_player *player);

/*
**	read_checks.c
*/

int					check_magic_header(int fd);
int					check_null_bytes(int fd);
int					check_exec_code_size(t_player *player);

/*
**	read_inits.c
*/

void				read_champion_name(t_player *player);
void				read_champion_comment(t_player *player);
void				read_exec_code(t_player *player);

/*
**	arena_init.c
*/

void				arena_initialization(t_vm *vm);

# endif 