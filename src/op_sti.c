/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:21:05 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:33:06 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_sti(t_vm *vm, t_proc *p)
{
	int argv[3];

	if (arg_checker(vm, p))
	{
		argv[1] = get_arg_value(vm, p, 1);
		argv[2] = get_arg_value(vm, p, 2);
		argv[0] = (short)((argv[1] + argv[2]) % IDX_MOD);
		if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 4) == 4)
		{
			ft_printf("P %4d | sti r%d %d %d\n", p->num,
				p->arg_v[0], argv[1], argv[2]);
			ft_printf("       | -> store to %d + %d = %d ",
				argv[1], argv[2], argv[1] + argv[2]);
			ft_printf("(with pc and mod %d)\n", p->pc + argv[0]);
		}
		update_map(vm, p, p->arg_v[0], p->pc + argv[0]);
	}
}
