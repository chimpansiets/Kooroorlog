/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 14:12:56 by svoort         #+#    #+#                */
/*   Updated: 2019/12/04 13:48:43 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define IN		0
# define OUT	1
# define EXT	".cor"
# define HEADER_SIZE (16 + PROG_NAME_LENGTH + COMMENT_LENGTH)
# define FIX_SIZE_ERR "Program too big (Exceed CHAMP_MAX_SIZE)"

# define DEBUG_LEVEL_NONE 0
# define DEBUG_LEVEL_COMP 1
# define DEBUG_LEVEL_COMP_ARGS 2
# define DEBUG_LEVEL_COMP_INFO 3

# define LABEL_CHECK (state & 1 << 6)
# define INSTRUCTION_CHECK (state & 1 << 5)
# define REG_CHECK (state & 1 << 4)
# define SEPARATOR_CHECK (state & 1 << 3)
# define DIRECT_LABEL_CHECK (state & 1 << 2)
# define DIRECT_VAL_CHECK (state & 1 << 1)
# define INDIRECT_VAL_CHECK (state & 1)

# define ENCODING_REG(x) (x & 2 && !(x & 1))
# define ENCODING_DIRECT(x) (!(x & 2) && x & 1)
# define ENCODING_INDIRECT(x) (x & 2 && x & 1)

# include <stdio.h> // remove this
# include <limits.h>
# include <errno.h>
# include <stdbool.h>
# include "libft.h"
# include "op.h"

typedef struct e_component	t_component;

// typedef enum	e_instructions {
// 	live, ld, st, add, sub,
// 	and, or, xor, zjmp, ldi,
// 	sti, fork, lld, lldi, lfork,
// 	aff
// }				t_instructions;

static const char	*instructions[] = {
	"live", "ldi", "sti", "st", "add", 
	"sub", "and", "or", "xor", "zjmp",
	"ld", "fork", "lldi", "lld", "lfork",
	"aff"
};

static const int	instruction_opcodes[] = {
	1, 10, 11, 3, 4, 5, 6, 7, 8, 9, 2,
	12, 14, 13, 15, 16
};

static const char	*instructions_label_2[] = {
	"zjmp", "ldi", "sti", "fork", "lldi",
	"lfork"
};

typedef enum	e_error {
	amount_args,
	file_not_found,
	lexical_error,
	syntax,
	name_missing,
	comment_missing,
	instr_not_found
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
	indirect_val,
	comment,
	champ_name,
	champ_comment
}				t_token;

typedef struct	e_argument {
	char		*str;
	t_token		type;
	size_t		byte_size;
}				t_argument;

struct			e_component {
	char			*str;
	char			*encoding_byte;
	unsigned char	codage_octal;
	t_token			type;
	uint32_t		pos;
	uint8_t			len;
	t_argument 		arguments[3];
	size_t			byte_size;
	size_t			label_size;
};

typedef struct	e_file {
	t_component	*components;
	int			fd;
	char		*filename;
	char		*file_buffer;
	char		has_name;
	char		has_comment;
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
**	lexical_parser.c
*/

void			lexical_analysis(t_file *in);

/*
**	component.c
*/

void			create_component(t_file *in, t_component components[2048], int *index);

/*
**	component_checks.c
*/

int				is_separator(char *buffer, int index);
int				is_direct_label(char *buffer, int index);
int				is_label(char *buffer, int index);
int				is_register(char *buffer, int index);
int				is_direct(char *buffer, int index);
int				is_indirect(char *buffer, int index);
int				is_instruction(char *buffer, int index);
int				is_comment(char *buffer, int index);
int				is_champ_name(char *buffer, int index);
int				is_champ_comment(char *buffer, int index);

/*
**	component_init.c
*/

void			init_component(t_token type, t_component *component, char *buffer, int index);

/*
**	syntax_analysis.c
*/

void			syntax_analysis(t_component *components);

/*
**	init_outfile.c
*/

t_file			change_extension(t_file in);

/*
**	write_magic_to_file.c
*/

void			write_reverse_int(int fd, int value);
void			write_reverse_2bytes(int fd, int16_t value);
void			write_magic_to_file(t_file in, t_file out);

/*
**	init_arguments.c
*/

void			init_arguments(t_component *component);

/*
**	write_exec_code.c
*/

void			write_champ_exec_code(t_file in, t_file out);

#endif
