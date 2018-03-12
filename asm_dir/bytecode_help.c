/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:57:56 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 17:11:11 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int					ft_is_need_arg_code(char *inst)
{
	int				i;

	i = 0;
	ft_strcmp(inst, "live") == 0 ? i++ : 0;
	ft_strcmp(inst, "zjmp") == 0 ? i++ : 0;
	ft_strcmp(inst, "fork") == 0 ? i++ : 0;
	ft_strcmp(inst, "lfork") == 0 ? i++ : 0;
	if (i != 0)
		return (1);
	else
		return (0);
}

int					ft_spec_case(char *inst, int n)
{
	int				i;

	i = 0;
	((ft_strcmp(inst, "sti") == 0 && (n == 2 || n == 3)) ? i++ : 0);
	((ft_strcmp(inst, "ldi") == 0 && (n == 1 || n == 2)) ? i++ : 0);
	((ft_strcmp(inst, "lldi") == 0 && (n == 1 || n == 2)) ? i++ : 0);
	ft_strcmp(inst, "fork") == 0 ? i++ : 0;
	ft_strcmp(inst, "lfork") == 0 ? i++ : 0;
	((ft_strcmp(inst, "zjmp") == 0)) ? i++ : 0;
	if (i != 0)
		return (1);
	else
		return (0);
}

int					ft_get_max(t_line_list *list)
{
	if (list == NULL)
		return (0);
	while (list->next)
		list = list->next;
	return (list->ent.length);
}
