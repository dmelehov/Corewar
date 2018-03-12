/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:00:45 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 14:00:47 by dshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			ft_write(unsigned char *bytes, int code, int *i, int count)
{
	if (count == 1)
	{
		bytes[*i] = code;
		*i += 1;
	}
	else if (count == 2)
	{
		bytes[*i] = code >> 8;
		bytes[*i + 1] = (code & TWO_BYTE_MASK);
		*i += 2;
	}
	else if (count == 4)
	{
		bytes[*i] = (code >> 24);
		bytes[*i + 1] =
				(code & FOUR_BYTE_MASK_1) >> 16;
		bytes[*i + 2] =
				(code & FOUR_BYTE_MASK_2) >> 8;
		bytes[*i + 3] = (code & FULL_BYTE);
		*i += 4;
	}
}

void			ft_arg_code(unsigned char *bytes, t_line_list *list, int *index)
{
	int			byte;

	if (ft_is_need_arg_code(list->ent.com[0]) == 1)
		return ;
	byte = 0;
	(list->ent.f_type == T_REG) ? (byte |= REG_MASK_1) : (0);
	(list->ent.f_type == T_IND) ? (byte |= IND_MASK_1) : (0);
	(list->ent.f_type == T_DIR) ? (byte |= DIR_MASK_1) : (0);
	(list->ent.s_type == T_REG) ? (byte |= REG_MASK_2) : (0);
	(list->ent.s_type == T_IND) ? (byte |= IND_MASK_2) : (0);
	(list->ent.s_type == T_DIR) ? (byte |= DIR_MASK_2) : (0);
	(list->ent.t_type == T_REG) ? (byte |= REG_MASK_3) : (0);
	(list->ent.t_type == T_IND) ? (byte |= IND_MASK_3) : (0);
	(list->ent.t_type == T_DIR) ? (byte |= DIR_MASK_3) : (0);
	bytes[(*index)++] = byte;
}

unsigned char	ft_get_op(char *inst, char *line)
{
	int			i;

	i = -1;
	while (g_op_tab[++i].name && ft_strcmp(inst, g_op_tab[i].name) != 0)
		;
	if (g_op_tab[i].opcode == 0)
	{
		ft_printf("bad instr in line %s\n", line);
		return (0);
	}
	else
		return (g_op_tab[i].opcode);
}

int				ft_param_code(t_main *main, char **tab, int *index)
{
	int			i;

	i = 1;
	while (tab[i])
	{
		if (tab[i][0] == 'r')
			ft_write(main->bytes, ft_atoi(&(tab[i][1])), index, 1);
		else if (tab[i][0] != '%')
			ft_write(main->bytes, ft_atoi(tab[i]), index, 2);
		else if (tab[i][0] == '%')
		{
			if (ft_spec_case(tab[0], i) == 1)
				ft_write(main->bytes, ft_atoi_1(&(tab[i][1])), index, 2);
			else
				ft_write(main->bytes, ft_atoi_1(&(tab[i][1])), index, 4);
		}
		i += 1;
	}
	return (0);
}

int				ft_bytecode(t_line_list *list, t_main *main)
{
	int			i;
	int			size;

	size = ft_get_max(list) + 1;
	if ((main->bytes = (unsigned char*)malloc((size_t)size)) == NULL)
		ft_err("malloc", -1);
	i = -1;
	while (++i < size)
		main->bytes[i] = 0;
	i = 0;
	while (list)
	{
		if (ft_get_op(list->ent.com[0], list->ent.r_line) == 0)
			return (-1);
		else
			main->bytes[i] = ft_get_op(list->ent.com[0], list->ent.r_line);
		i += 1;
		ft_arg_code(main->bytes, list, &i);
		ft_param_code(main, list->ent.com, &i);
		list = list->next;
	}
	return (0);
}
