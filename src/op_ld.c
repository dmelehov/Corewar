/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:17:37 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:31:52 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_ld(t_vm *vm, t_proc *p)
{
	if (arg_checker(vm, p))
	{
		p->arg_v[0] = get_arg_value(vm, p, 0);
		p->reg[p->arg_v[1]] = p->arg_v[0];
		p->carry = (p->reg[p->arg_v[1]] == 0 ? 1 : 0);
		if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 4) == 4)
			ft_printf("P %4d | ld %d r%d\n", p->num,
				p->reg[p->arg_v[1]], p->arg_v[1]);
	}
}
