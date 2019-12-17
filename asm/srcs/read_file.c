/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:05:19 by svoort         #+#    #+#                */
/*   Updated: 2019/12/17 14:43:43 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern char		print_buffer;

void	read_file_content(t_file *in, char *filename)
{
	int		ret;
	char	buf[2];

	in->file_buffer = ft_memalloc(sizeof(char) * 4096);//checken of het meer kan zijn
	while ((ret = read(in->fd, buf, 1)) > 0)
	{
		buf[1] = '\0';
		ft_strcat(in->file_buffer, buf);
	}
	if (print_buffer)
		ft_printf("%s", in->file_buffer);
	in->filename = filename;
}

void	check_and_read_file_content(t_file *in, char *filename)
{
	in->fd = open(filename, O_RDONLY);

	if (in->fd < 0)
		print_error(file_not_found, Err, filename);
	read_file_content(in, filename);
	lexical_analysis(in);
	/*
	**	this will check if the executable code is in correct order,
	**	if valid arguments are given after instruction, etc.
	*/
	// syntax_analysis(in->components);
	if (!in->has_name)
		print_error(name_missing, Err, NULL);
	else if (!in->has_comment)
		print_error(comment_missing, Err, NULL);
}
