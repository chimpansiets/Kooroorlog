/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 14:14:01 by svoort         #+#    #+#                */
/*   Updated: 2019/12/03 13:30:59 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# define MAX_PLAYERS 4

# include "libft.h"

typedef enum		e_error {
	amount_args,
	invalid_flag,
	invalid_id,
	invalid_player_file,
}					t_error;

typedef struct		e_player {
	int				id;
	char			*name;
	char			*comment;
	char			*file_name;
	int				ex_code_size;
	int				ex_code;
	struct t_player	*next;
}					t_player;

typedef struct		e_vm {
	int				total_players;
	t_player		*players;
}					t_vm;

#endif
