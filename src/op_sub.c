/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:21:29 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:33:14 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_sub(t_vm *vm, t_proc *p)
{
	if (arg_checker(vm, p))
	{
		p->reg[p->arg_v[2]] = p->reg[p->arg_v[0]] - p->reg[p->arg_v[1]];
		p->carry = (p->reg[p->arg_v[2]] == 0 ? 1 : 0);
		if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 4) == 4)
			ft_printf("P %4d | sub r%d r%d r%d\n",
				p->num, p->arg_v[0], p->arg_v[1], p->arg_v[2]);
	}
}
