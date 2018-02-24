/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:19:49 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:32:11 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_lld(t_vm *vm, t_proc *p)
{
	if (arg_checker(vm, p))
	{
		p->arg_v[0] = get_arg_value(vm, p, 0);
		p->reg[p->arg_v[1]] = p->arg_v[0];
		p->carry = (p->reg[p->arg_v[1]] == 0 ? 1 : 0);
		ft_printf("P%5d | lld %d r%d\n", p->num,
			   p->reg[p->arg_v[1]], p->arg_v[1]);
	}
}
