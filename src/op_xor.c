/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:21:47 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:33:32 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_xor(t_vm *vm, t_proc *p)
{
	int argv[2];

	if (arg_checker(vm, p))
	{
		argv[0] = get_arg_value(vm, p, 0);
		argv[1] = get_arg_value(vm, p, 1);
		p->reg[p->arg_v[2]] = (argv[0] ^ argv[1]);
		p->carry = (p->reg[p->arg_v[2]] == 0 ? 1 : 0);
		if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 4) == 4)
			ft_printf("P %4d | xor %d %d r%d\n", p->num,
				argv[0], argv[1], p->arg_v[2]);
	}
}
