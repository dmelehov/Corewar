/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:31:16 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 22:31:30 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static unsigned int		parse_magic(void *data, unsigned int len, unsigned int size)
{
	unsigned int		magic;

	magic = 0;
	if (len < size)
		magic = get_value_from_map(data, 0, len);
	if (magic != COREWAR_EXEC_MAGIC)
		return (0);
	return (magic);
}

static char				*parse_name(unsigned char *data, unsigned int len, unsigned int size)
{
	unsigned int		start;
	unsigned int		i;
	char				*name;

	start = sizeof(unsigned int);
	i = 0;
	name = NULL;
	if ((name = (char *)malloc(sizeof(char) * len)))
	{
		if (len < size)
		{
			while (i < len && start < size)
				name[i++] = data[start++];
		}
		name[i] = '\0';
	}
	return (name);
}

static char				*parse_comment(unsigned char *data, unsigned int len, unsigned int size)
{
	char				*comment;
	unsigned int		i;
	unsigned int		start;

	start = sizeof(unsigned int) + (PROG_NAME_LENGTH) + 8;
	i = 0;
	comment = NULL;
	if ((comment = (char *)malloc(sizeof(char) * len)))
	{
		if (len < size)
		{
			while (i < len && start < size)
				comment[i++] = data[start++];
		}
		comment[i] = '\0';
	}
	return (comment);
}

static char				*parse_prog(unsigned char *data, unsigned int len, unsigned int size)
{
	char				*prog;
	unsigned int		i;
	unsigned int		start;

	start = sizeof(unsigned int) + (PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 12;
	i = 0;
	prog = NULL;
	if ((prog = (char *)malloc(sizeof(char) * len)))
	{
		if (len < size)
		{
			while (i < len && start < size)
				prog[i++] = data[start++];
		}
		prog[i] = '\0';
	}
	return (prog);
}

t_header				*parse_header(unsigned char *data, unsigned int size)
{
	t_header		*header;
	unsigned int	magic;
	char			*prog_name;
	char			*comment;
	char			*prog;

	header = NULL;
	if ((magic = parse_magic(data, 4, size)))
	{
		prog_name = parse_name(data, (PROG_NAME_LENGTH) + 1, size);
		comment = parse_comment(data, (COMMENT_LENGTH) + 1, size);
		prog = parse_prog(data, size - ((PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16), size);
		header = init_header(magic, prog_name, comment, prog);
		header->prog_size = size - ((PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16);
	}
	return (header);
}
