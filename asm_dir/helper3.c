/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:12:39 by dmelehov          #+#    #+#             */
/*   Updated: 2018/03/06 17:43:12 by dshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				ft_check_lables(t_line_list *list)
{
	int			i;

	while (list)
	{
		i = -1;
		while (list->ent.com[++i])
		{
			if (list->ent.com[i] != NULL)
			{
				if ((list->ent.com[i][0] == ':') ||
					(list->ent.com[i][0] == '%'
					&& list->ent.com[i][1] == ':'))
					if (ft_check_label_char(list, i) == -1)
						return (-1);
			}
		}
		list = list->next;
	}
	return (0);
}

int				ft_is_delete(char **com)
{
	if (com[0] == NULL)
		return (1);
	if (com[0] != NULL && (ft_strcmp(com[0], NAME_CMD_STRING) == 0
				|| ft_strcmp(com[0], COMMENT_CMD_STRING) == 0
				|| ft_is_label(com[0])))
		return (1);
	else
		return (0);
}

int				ft_got_thresh(t_line_list *list)
{
	while (list)
	{
		if (ft_is_delete((list->ent.com)))
			return (1);
		list = list->next;
	}
	return (-1);
}

void			ft_ad_t(t_line_list *line, int com_n, int type)
{
	if (com_n == 0)
		line->ent.f_type = type;
	else if (com_n == 1)
		line->ent.s_type = type;
	else if (com_n == 2)
		line->ent.t_type = type;
}

int				ft_is_reg(char *str)
{
	int	i;

	i = 0;
	if (str[0] != 'r')
		return (-1);
	str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (1);
}
