/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:02:30 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 16:19:30 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_find_inst(char *inst)
{
	int	i;

	i = 0;
	while (g_op_tab[i].name && ft_strequ(g_op_tab[i].name, inst) != 1)
		i++;
	if (i > 15)
		return (-1);
	else
		return (i);
}

int		ft_check_args_n(t_line_list *list)
{
	int	par;

	par = ft_find_inst(list->ent.com[0]);
	if (par == -1)
	{
		ft_printf("Invalid instruction at token [TOKEN]");
		ft_printf("[%03d", list->ent.nbr);
		ft_printf(":%03d]", ft_get_pos(list->ent.r_line, list->ent.com[0]) + 1);
		ft_printf(" %s \"%s\"\n",
			ft_get_l_i_str(list->ent.com[0]), list->ent.com[0]);
		return (-1);
	}
	if (g_op_tab[par].arg_num != list->ent.args_n)
	{
		ft_printf("Invalid parameter %d type ", g_op_tab[par].arg_num);
		ft_printf("register for instruction %s\n", g_op_tab[par].name);
		return (-1);
	}
	return (0);
}

int		ft_check_arg(t_line_list *list, int n)
{
	int	i;
	int	type;

	type = -1;
	n == 1 ? type = list->ent.f_type : (0);
	n == 2 ? type = list->ent.s_type : (0);
	n == 3 ? type = list->ent.t_type : (0);
	i = ft_find_inst(list->ent.com[0]);
	if (type != T_DIR && type != T_REG && type != T_IND && type != INST)
		return (ft_print_err_lexical(list, n));
	if (type == INST)
		return (ft_print_err_inst(list, n));
	if ((g_op_tab[i].args[n - 1] & type) == 0)
	{
		ft_printf("Invalid parameter %d type register", n - 1);
		ft_printf(" for instruction %s\n", g_op_tab[i].name);
		return (-1);
	}
	if (type == T_REG)
	{
		if (ft_atoi(list->ent.com[n] + 1) > REG_NUMBER)
			return (ft_print_err_arg(list, n));
	}
	return (0);
}

int		ft_cycle_body(t_line_list *list)
{
	int	res;

	res = 0;
	if (list->ent.f_type != 0)
		res = ft_check_arg(list, 1);
	if (list->ent.s_type != 0)
		res += ft_check_arg(list, 2);
	if (list->ent.t_type != 0)
		res += ft_check_arg(list, 3);
	if (res < 0)
		return (-1);
	return (0);
}

int		ft_is_valid(t_line_list *list)
{
	t_line_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_check_args_n(tmp) == -1)
			return (-1);
		if (ft_cycle_body(tmp) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
