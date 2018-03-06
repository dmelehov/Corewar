/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:01:38 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 16:39:57 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			ft_inst_check(char *str)
{
	int		i;

	i = -1;
	while (g_op_tab[++i].name)
		if (ft_strequ(g_op_tab[i].name, str) == 1)
			return (1);
	return (0);
}

t_line_list	*get_last(t_line_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

int			ft_is_empty(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i;
		if (str[i] == '#' || str[i] == ';')
			while (str[j])
				str[j++] = 0;
		i += 1;
	}
	i = -1;
	if (ft_strlen(str) == 0)
	{
		free(str);
		return (1);
	}
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != 't')
			return (0);
	}
	free(str);
	return (1);
}

int			ft_get_pos(const char *big, const char *little)
{
	int j;
	int l;
	int i;

	j = 0;
	i = 0;
	l = (int)ft_strlen(little);
	if (l-- == 0)
		return (0);
	while (big[i])
	{
		while (big[i] == little[j])
		{
			if (j == l)
				return (i - l);
			j++;
			i++;
		}
		j = 0;
		i++;
	}
	return (0);
}

char		*ft_get_l_i_str(char *str)
{
	if (ft_is_label(str))
		return ("LABEL");
	else
		return ("INSTRUCTION");
}
