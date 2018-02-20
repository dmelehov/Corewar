//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_add(t_vm *vm, t_proc *p)
{
	if (arg_checker(vm, p))
	{
		p->reg[p->arg_v[2]] = p->reg[p->arg_v[0]] + p->reg[p->arg_v[1]];
		p->carry = (p->reg[p->arg_v[2]] == 0 ? 1 : 0);
		printf("P %d | add r%d r%d r%d\n",
			   p->num, p->arg_v[0], p->arg_v[1], p->arg_v[2]);
	}
	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 3)) % MEM_SIZE;
}

