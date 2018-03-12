/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_lable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:02:09 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 16:04:03 by dshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				ft_is_duplicate(t_line_list *list)
{
	t_line_list	*tmp;

	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (ft_is_label(tmp->ent.com[0])
				&& ft_strequ(list->ent.com[0], tmp->ent.com[0]))
			{
				ft_printf("error: this label defined more than one time: '");
				ft_printf("%s\n", tmp->ent.com[0]);
				return (-1);
			}
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (0);
}

char			*ft_get_bytes2(t_line_list *list, t_line_list *tmp)
{
	char		*ret;
	char		*tmp_s;

	tmp_s = ft_itoa(list->ent.pos - tmp->ent.pos);
	ret = ft_strnew(sizeof(ft_strlen(tmp_s) + 1));
	ret[0] = '%';
	ret[1] = '\0';
	ret = ft_strcat(ret, tmp_s);
	ret[ft_strlen(ret) + 1] = '\0';
	free(tmp_s);
	return (ret);
}

char			*ft_byte(t_line_list *list, t_line_list *tmp, int i, char *err)
{
	char		*cmd;
	int			flag;

	flag = 0;
	tmp->ent.com[i][0] == ':' ? flag = 1 : (0);
	tmp->ent.com[i][0] == ':' ? cmd = tmp->ent.com[i] + 1 : (0);
	tmp->ent.com[i][0] != ':' ? cmd = tmp->ent.com[i] + 2 : (0);
	while (list)
	{
		if (list->ent.com[0]
			&& ft_strncmp(cmd, list->ent.com[0], ft_strlen(cmd)) == 0
			&& (list->ent.com[0][ft_strlen(cmd)] == ':'))
		{
			if (flag == 0)
				return (ft_get_bytes2(list, tmp));
			return (ft_itoa(list->ent.pos - tmp->ent.pos));
		}
		list = list->next;
	}
	ft_printf("No such label %s", err + 1);
	ft_printf(" while attempting to dereference token [TOKEN]");
	ft_printf("[%03d:%d]", tmp->ent.nbr, ft_get_pos(tmp->ent.r_line, err) + 1);
	err[0] == '%' ? ft_printf(" ") : ft_printf(" IN");
	ft_printf("DIRECT_LABEL \"%s\"\n", err);
	return (NULL);
}

int				ft_redirect_lables(t_line_list *list)
{
	t_line_list	*tmp;
	int			i;
	char		*error_c;

	tmp = list;
	while (tmp)
	{
		i = -1;
		while (tmp->ent.com[++i])
		{
			if ((tmp->ent.com[i] && tmp->ent.com[i][0] == ':'
				&& tmp->ent.com[i][1]) || (tmp->ent.com[i][0] == '%'
					&& tmp->ent.com[i][1] == ':' && tmp->ent.com[i][2]))
			{
				error_c = ft_strdup(tmp->ent.com[i]);
				free(tmp->ent.com[i]);
				tmp->ent.com[i] = ft_byte(list, tmp, i, error_c);
				free(error_c);
				if (tmp->ent.com[i] == NULL)
					return (-1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int				ft_remove_labels(t_line_list *list)
{
	if (ft_check_first_label(list) == -1)
		return (-1);
	if (ft_check_lables(list) == -1)
		return (-1);
	if (ft_is_duplicate(list) == -1)
		return (-1);
	if (ft_redirect_lables(list) == -1)
		return (-1);
	return (0);
}
