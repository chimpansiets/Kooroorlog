/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/26 18:40:34 by svoort         #+#    #+#                */
/*   Updated: 2019/07/24 12:39:39 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8128
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft.h"

typedef struct	s_i
{
	char		*line;
	int			i;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
