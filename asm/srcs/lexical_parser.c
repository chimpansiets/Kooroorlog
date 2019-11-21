/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexical_parser.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 09:26:16 by svoort         #+#    #+#                */
/*   Updated: 2019/11/21 15:10:08 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern char		g_verbose;

char	*get_arg_type(t_token type)
{
	if (type == direct_label)
		return ("direct_label");
	else if (type == direct_val)
		return ("direct_val");
	else if (type == indirect_val)
		return ("indirect_val");
	else if (type == reg)
		return ("reg");
	else
		return (NULL);
}

static void	print_components(t_component components[2048])
{
	int	i;

	i = 0;
	while (components[i].str != NULL)
	{
		ft_printf("%s\n", components[i].str);
		if (components[i].type == instruction && g_verbose == DEBUG_LEVEL_COMP_ARGS)
		{
			ft_printf("arg1: %s\n", components[i].arguments[0].str);
				ft_printf("type: %s\n", get_arg_type(components[i].arguments[0].type));
			ft_printf("arg2: %s\n", components[i].arguments[1].str);
			ft_printf("type: %s\n", get_arg_type(components[i].arguments[1].type));
				ft_printf("arg3: %s\n", components[i].arguments[2].str);
			ft_printf("type: %s\n", get_arg_type(components[i].arguments[2].type));
		}
		i++;
	}
}

void		lexical_analysis(t_file *in)
{
	t_component	components[2048];
	int			index;

	index = 0;
	ft_bzero(components, sizeof(t_component) * 2048);
	while (in->file_buffer[index] != '\0')
		create_component(in, components, &index);
	if (g_verbose == 1)
		print_components(components);
	in->components = components;
}
