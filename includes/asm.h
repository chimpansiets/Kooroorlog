/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 14:12:56 by svoort         #+#    #+#                */
/*   Updated: 2019/11/01 11:29:45 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define IN		0
# define OUT	1
# define EXT	".cor"
# define HEADER_SIZE (16 + PROG_NAME_LENGTH + COMMENT_LENGTH)
# define FIX_SIZE_ERR "Program too big (Exceed CHAMP_MAX_SIZE)"

# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <stdbool.h>
# include "libft.h"
# include "op.h"

typedef struct e_component	t_component;

typedef enum	e_error {
	amount_args,
	file_not_found,
	lexical_error
}				t_error;

typedef enum	e_severity {
	Err,
	Warn
}				t_severity;

typedef enum	e_token {
	none,
	label,
	instruction,
	reg,
	separator,
	direct_label,
	direct_val,
	comment
}				t_token;

struct			e_component {
	t_token		type;
	u_int32_t	pos;
	u_int8_t	len;
	t_component	*next;
};

typedef struct	e_file {
	int			fd;
	char		*filename;
	char		file_buffer[BUFFER_SIZE];
}				t_file;

/*
**	error.c
*/

int				print_error(t_error type, t_severity severity, \
				char *error_str);

/*
**	read_file.c
*/

void			read_file_content(t_file *in, char *filename);
void			check_and_read_file_content(t_file *in, char *filename);

/*
**	parser.c
*/

void			parse_components(t_file *in);

/*
**	component.c
*/

void			create_component(t_file *in, t_component components[2048], int *index);

/*
**	component_checks.c
*/

int				is_separator(char *buffer, int index);

#endif
