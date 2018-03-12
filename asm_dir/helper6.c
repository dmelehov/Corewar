/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:34:35 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/12 10:36:18 by dshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void				ft_add_space3(char **str)
{
	int				i;
	int				j;
	char			*res;

	i = 0;
	res = ft_strnew(ft_strlen(*str) + 2);
	while ((*str)[i] != ':' && (*str)[i] != '%')
	{
		res[i] = (*str)[i];
		i++;
	}
	res[i] = ' ';
	j = i;
	i++;
	while ((*str)[j])
	{
		res[i] = (*str)[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free(*str);
	*str = res;
}

void				ft_skip_stuff(int *i, int *j, int *k, char **str)
{
	*i = 0;
	*k = 0;
	while ((*str)[*i] != 0 && ((*str)[*i] == '\t' || (*str)[*i] == ' '))
		(*i)++;
	*j = *i;
	while ((*str)[*i] != '%' && (*str)[*i] != 0)
		(*i)++;
}

void				ft_add_space2(char **str)
{
	int				i;
	int				j;
	char			*tmp;
	int				k;

	ft_skip_stuff(&i, &j, &k, str);
	if ((*str)[i] == ' ' || (*str)[i] == '\t')
		return ;
	if (i < (int)ft_strlen(*str) - 1)
	{
		tmp = ft_strnew(i + 2);
		while (j < i)
			tmp[k++] = (*str)[j++];
		tmp[k] = '\0';
		i = 0;
		while (g_op_tab[i].name)
			if (ft_strequ(tmp, g_op_tab[i++].name))
			{
				ft_add_space3(str);
				free(tmp);
				return ;
			}
		free(tmp);
	}
}

void				ft_add_space(char **str)
{
	char			*tmp;
	int				i;

	i = 0;
	if (ft_is_label(*str))
	{
		tmp = ft_strnew(ft_strlen(*str) + 2);
		while ((*str)[i])
		{
			tmp[i] = (*str)[i];
			i++;
		}
		tmp[i] = ' ';
		tmp[i + 1] = '\0';
		free(*str);
		*str = tmp;
	}
	else
		ft_add_space2(str);
}

int					ft_check_len(t_main *main)
{
	if (ft_strlen(main->comment) > COMMENT_LENGTH)
	{
		ft_printf("Champion comment too long (Max length 2048)\n");
		return (-1);
	}
	else if (ft_strlen(main->name) > PROG_NAME_LENGTH)
	{
		ft_printf("Champion name too long (Max length 128)\n");
		return (-1);
	}
	return (0);
}
