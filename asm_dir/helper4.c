/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:43:54 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 17:43:56 by dshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int					ft_print_err_inst(t_line_list *list, int n)
{
	ft_printf("Syntax error in token [TOKEN]");
	ft_printf("[%03d:", list->ent.nbr);
	ft_printf("%03d", ft_get_pos(list->ent.r_line, list->ent.com[n]) + 1);
	ft_printf("] INSTRUCTION \"%s\"\n", list->ent.com[n]);
	return (-1);
}

int					ft_print_err_lexical(t_line_list *list, int n)
{
	ft_printf("Lexical error at ");
	ft_printf("[%d:", list->ent.nbr);
	ft_printf("%d]\n", ft_get_pos(list->ent.r_line, list->ent.com[n]) + 1);
	return (-1);
}

int					ft_print_err_arg(t_line_list *list, int n)
{
	ft_printf("Syntax error in token [TOKEN]");
	ft_printf("[%03d:", list->ent.nbr);
	ft_printf("%03d", ft_get_pos(list->ent.r_line, list->ent.com[n]) + 1);
	ft_printf("] INSTRUCTION \"%s\"\n", list->ent.com[n]);
	return (-1);
}

t_line_list			*create_file(char *line, int nbr)
{
	t_line_list		*new;

	if ((new = (t_line_list*)malloc(sizeof(t_line_list))))
	{
		new->ent.r_line = line;
		if ((new->ent.com = ft_split_cmd(line)) == NULL)
			return (NULL);
		new->ent.args_n = 0;
		new->ent.f_type = 0;
		new->ent.s_type = 0;
		new->ent.t_type = 0;
		new->ent.pos = 0;
		new->ent.length = 0;
		new->next = NULL;
		new->ent.nbr = nbr;
	}
	else
	{
		ft_putstr("error: malloc\n");
		return (NULL);
	}
	return (new);
}

int					check_eos(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}
