/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 14:14:01 by svoort         #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/12/03 13:30:59 by avan-rei      ########   odam.nl         */
=======
/*   Updated: 2019/12/03 11:51:33 by svoort        ########   odam.nl         */
>>>>>>> 9aa38c2e753558438cf787d1bfa774c98953e96e
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

<<<<<<< HEAD
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
=======
# include <stdio.h> // remove this
# include <limits.h>
# include <errno.h>
# include <stdbool.h>
# include "libft.h"
# include "op.h"
>>>>>>> 9aa38c2e753558438cf787d1bfa774c98953e96e

#endif
