/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/26 18:39:48 by svoort         #+#    #+#                */
/*   Updated: 2019/07/25 13:19:57 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list				*check_list(const int fd, t_list **list)
{
	t_list			*new_node;
	t_list			*tmp;

	new_node = 0;
	tmp = *list;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	new_node = ft_lstnew("\0", 1);
	new_node->content_size = fd;
	ft_lstadd(list, new_node);
	return (*list);
}

t_gnl				line_get(char *content)
{
	char			*cont;
	t_gnl			line_i;

	line_i.i = 0;
	cont = (char *)content;
	while (cont[line_i.i] != '\n' && cont[line_i.i] != '\0')
	{
		line_i.i++;
	}
	line_i.line = ft_strnew(line_i.i + 1);
	if (line_i.i == 0)
		return (line_i);
	line_i.line = ft_strncpy(line_i.line, cont, line_i.i);
	line_i.line[line_i.i + 1] = 0;
	return (line_i);
}

int					my_read(const int fd, char **old)
{
	char			buf[BUFF_SIZE + 1];
	int				r;
	char			*tmp;

	r = 1;
	tmp = 0;
	while (r > 0)
	{
		r = read(fd, buf, BUFF_SIZE);
		if (r < 0)
			return (-1);
		if (r > 0)
		{
			buf[r] = 0;
			tmp = ft_strjoin(*old, buf);
			ft_strdel(&(*old));
			*old = tmp;
			if ((ft_memchr(buf, '\n', BUFF_SIZE)) != NULL ||
				r < BUFF_SIZE)
				break ;
		}
	}
	return (r);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*to_work;
	t_gnl			line_i;
	int				r;
	char			*tmp;

	tmp = 0;
	if (fd < 0)
		return (-1);
	to_work = check_list(fd, &list);
	r = my_read(fd, (char **)&to_work->content);
	if (r < 0)
		return (-1);
	line_i = line_get(to_work->content);
	*line = line_i.line;
	if (r == 0 && !ft_strlen(to_work->content) && !ft_strlen(*line))
		return (0);
	tmp = to_work->content;
	if (((char *)to_work->content)[line_i.i] != '\0')
		to_work->content = ft_strdup(to_work->content + (line_i.i + 1));
	else
		to_work->content = ft_strnew(0);
	ft_strdel(&tmp);
	return (1);
}
