/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 09:42:47 by svoort         #+#    #+#                */
/*   Updated: 2019/11/02 14:03:46 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "asm.h"

static char	is_labelchar(char c)
{
	if (strchr(LABEL_CHARS, c) != NULL)
		return (1);
	else
		return (0);
}

static void	init_label_component(t_component *component, char *buffer, int index)
{
	int		i;

	i = index;
	while (buffer[i] && is_labelchar(buffer[i]))
		i++;
	component->type = label;
	component->pos = index;
	component->len = i - index;
	ft_printf("label: %s\n", ft_strndup(&buffer[index], i - index));
	ft_printf("label_len: %i\n", i - index);
	ft_printf("label_pos: %i\n", component->pos);
}

static void	init_instruction_component(t_component *component, char *buffer, int index)
{
	int		i;

	i = 0;
	while (i < 15)
	{
		if (ft_strnequ(&buffer[index], instructions[i], ft_strlen(instructions[i])))
		{
			component->type = instruction;
			component->str = ft_strndup(&buffer[index], ft_strlen(instructions[i]));
			component->len = ft_strlen(instructions[i]);
			component->pos = index;
			break ;
		}
		i++;
	}
	ft_printf("instruction: %s\n", component->str);
	ft_printf("instruction_len: %i\n", component->len);
	ft_printf("instruction_pos: %i\n", component->pos);
}

static void	init_reg_component(t_component *component, char *buffer, int index)
{
	char	atoi_string[32];
	int		i;
	int		j;

	i = index + 1;
	j = 0;
	if (buffer[index] == 'r')
	{
		while (buffer[i] && ft_isdigit(buffer[i]))
			atoi_string[j++] = buffer[i++];
		atoi_string[j] = '\0';
	}
	if (0 < ft_atoi(atoi_string) && ft_atoi(atoi_string) <= REG_NUMBER)
	{
		component->str = ft_strndup(&buffer[index], i - index);
		component->len = i - index;
		component->pos = index;
	}
	ft_printf("reg: %s\n", component->str);
	ft_printf("reg_len: %i\n", component->len);
	ft_printf("reg_pos: %i\n", component->pos);
}

static void	init_separator_component(t_component *component, char *buffer, int index)
{
	if (buffer[index] == ',')
	{
		component->type = separator;
		component->len = 1;
		component->pos = index;
		component->str = ft_strndup(&buffer[index], 1);
	}
	// else
	// 	print_error(syntax, Err, ft_itoa(index));
	ft_printf("separator: %s\n", component->str);
	ft_printf("separator_len: %i\n", component->len);
	ft_printf("separator_pos: %i\n", component->pos);
}

static char	*ft_strdup_label(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i] && ft_strchr(LABEL_CHARS, s1[i]))
		i++;
	s2 = (char *)ft_memalloc(i + 1);
	if (!s1 || !(s2))
		return (0);
	s2[i] = '\0';
	while (i > 0)
	{
		i--;
		s2[i] = s1[i];
	}
	return (s2);
}

static void	init_direct_label_component(t_component *component, char *buffer, int index)
{
	char	*label_name;

	if (buffer[index] == '%' && buffer[index + 1] == ':')
	{
		label_name = ft_strdup_label(&buffer[index + 2]);
		if (ft_strlen(label_name) > 0)
		{
			component->type = direct_label;
			component->str = ft_joinfree("%:", label_name, 2);
			component->pos = index;
			component->len = ft_strlen(component->str);
		}
	}
	ft_printf("direct_label: %s\n", component->str);
	ft_printf("direct_label_len: %i\n", component->len);
	ft_printf("direct_label_pos: %i\n", component->pos);
}

static void	init_direct_val_component(t_component *component, char *buffer, int index)
{
	int		i;

	i = index + 1;
	if (buffer[index] != '%')
		print_error(syntax, Err, ft_itoa(index));
	while (buffer[i] && buffer[i] >= 48 && buffer[i] <= 57)
		i++;
	component->str = ft_strndup(&buffer[index], i - index);
	component->pos = index;
	component->len = i - index;
	component->type = direct_val;
	ft_printf("direct_label: %s\n", component->str);
	ft_printf("direct_label_len: %i\n", component->len);
	ft_printf("direct_label_pos: %i\n", component->pos);
}

int		main(void)
{
	t_component component;

	init_label_component(&component, "       label_name:", 7);
	init_instruction_component(&component, "  lfork    ", 2);
	init_reg_component(&component, "   r12,   ", 3);
	init_separator_component(&component, "   ,  ", 3);
	init_direct_label_component(&component, "   %:label,  ", 3);
	init_direct_val_component(&component, "live: 23, ", 6);
	return (0);
}
