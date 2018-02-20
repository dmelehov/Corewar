//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_lld(t_vm *vm, t_proc *p)
{
	if (arg_checker(vm, p))
	{
		p->arg_v[0] = get_arg_value(vm, p, 0);
		p->reg[p->arg_v[1]] = p->arg_v[0];
		p->carry = (p->arg_v[0] == 0 ? 1 : 0);
		printf("P    %d | lld %d r%d\n", p->num,
			   p->reg[p->arg_v[1]], p->arg_v[1]);
	}
	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 1)) % MEM_SIZE;
}
