//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_st(t_vm *vm, t_proc *p)
{
	int adr;

	if (arg_checker(vm, p))
	{
		if (p->arg[1] == REG_CODE)
			p->reg[p->arg_v[1]]  = p->reg[p->arg_v[0]];
		else if (p->arg[1] == IND_CODE)
		{
			adr = p->pc + (p->arg_v[1] % IDX_MOD);
			update_map(vm, p, p->arg_v[0], adr);
		}
		printf("P    %d | st r%d %d\n", p->num, p->arg_v[0],  p->arg_v[1]);
	}
	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 2)) % MEM_SIZE;
}
