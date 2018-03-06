/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:47:54 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 17:47:58 by dshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				skip_wspcs(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else
			break ;
	}
	return (i);
}

int				read_helper(t_line_list **list, char *str, int *nbr)
{
	t_line_list	*tmp;

	tmp = *list;
	if (tmp)
	{
		tmp = get_last(tmp);
		if ((tmp->next = create_file(str, *nbr)) == NULL)
			return (-1);
	}
	else if ((*list = create_file(str, *nbr)) == NULL)
		return (-1);
	return (0);
}

void			some_modifying_two(char *s, char *ptr, char **res)
{
	char	*tmp;

	tmp = *res;
	ft_strclr(ptr);
	*res = ft_strjoin(*res, s);
	ft_strdel(&tmp);
	ft_strdel(&s);
}

char			*some_modifying(char **res, char *s)
{
	char	*tmp;
	char	*ptr;

	ptr = ft_strchr(s, 34);
	if (ptr == NULL)
	{
		tmp = *res;
		*res = ft_strjoin(*res, s);
		ft_strdel(&tmp);
		tmp = *res;
		*res = ft_strjoin(*res, "\n");
		ft_strdel(&tmp);
	}
	return (ptr);
}
