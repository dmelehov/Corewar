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
		p->carry = (p->reg[p->arg_v[1]] == 0 ? 1 : 0);
		printf("P%5d | lld %d r%d\n", p->num,
			   p->reg[p->arg_v[1]], p->arg_v[1]);
	}
}