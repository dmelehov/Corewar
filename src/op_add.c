/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:16:34 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:28:03 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_add(t_vm *vm, t_proc *p)
{
	if (arg_checker(vm, p))
	{
		p->reg[p->arg_v[2]] = p->reg[p->arg_v[0]] + p->reg[p->arg_v[1]];
		p->carry = (p->reg[p->arg_v[2]] == 0 ? 1 : 0);
		ft_printf("P%5d | add r%d r%d r%d\n",
			p->num, p->arg_v[0], p->arg_v[1], p->arg_v[2]);
	}
}
