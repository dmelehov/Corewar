/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:22:13 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:33:43 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_zjmp(t_vm *vm, t_proc *p)
{
	short int	ind;
	char		*s;
	int			pc;

	s = "FAILED";
	p->arg[0] = 2;
	ind = (short)(get_magic(vm->map, p->pc + 1, 2));
	if (vm->flags->n)
		del_proc(p);
	pc = p->pc;
	if (p->carry == 1)
	{
		s = "OK";
		p->pc = (p->pc + (ind % IDX_MOD)) % MEM_SIZE;
		p->cur_cmd = 0;
		if (p->pc < 0)
			p->pc += MEM_SIZE;
	}
	else
		p->pc = (p->pc + calc_shift(vm, p, 1)) % MEM_SIZE;
	if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 4) == 4)
		ft_printf("P %4d | zjmp %d %s\n", p->num, ind, s);
	if (ft_strequ("FAILED", s))
		if_jump_flag(vm, pc, p->pc, 1);
}
