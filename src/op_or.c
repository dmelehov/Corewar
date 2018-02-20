//
// Created by Dmitry Melehov on 2/20/18.
//

#include "../includes/vm.h"

void	op_or(t_vm *vm, t_proc *p)
{
	int	argv[2];

	if (arg_checker(vm, p))
	{

		argv[0] = get_arg_value(vm, p, 0);
		argv[1] = get_arg_value(vm, p, 1);
		p->reg[p->arg_v[2]] = (argv[0] | argv[1]);
		p->carry = (p->reg[p->arg_v[2]] == 0 ? 1 : 0);
		printf("P %d | or r%d r%d r%d\n", p->num,
			   p->arg_v[0], p->arg_v[1], p->arg_v[2]);
	}
	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 3)) % MEM_SIZE;
}
