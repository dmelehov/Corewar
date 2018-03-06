/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:20:12 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:32:50 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_lldi(t_vm *vm, t_proc *p)
{
	int argv[3];

	if (arg_checker(vm, p))
	{
		argv[0] = get_arg_value(vm, p, 0);
		argv[1] = get_arg_value(vm, p, 1);
		argv[2] = ((argv[0] + argv[1]) % MEM_SIZE);
		p->reg[p->arg_v[2]] = get_magic(vm->map, p->pc + argv[2], 4);
		p->carry = (p->reg[p->arg_v[2]] == 0 ? 1 : 0);
		if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 4) == 4)
		{
			ft_printf("P %4d | lldi %d %d r%d\n",
				p->num, argv[0], argv[1], p->arg_v[2]);
			ft_printf("       | -> load from %d + %d = %d ",
				argv[0], argv[1], argv[0] + argv[1]);
			ft_printf("(with pc %d)\n", p->pc + argv[0] + argv[1]);
		}
	}
}
