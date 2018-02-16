//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_ld(t_vm *vm, t_proc *p)
{
	int arg;
	int r;
	int t;

	arg = 0;
	r = vm->map[(p->pc + 6) % MEM_SIZE];
	t = (r > 0 && r < MEM_SIZE);
	if (p->arg[0] == DIR_CODE && t)
	{
		arg = get_magic(vm->map, p->pc + 2, 4);
	}
	else if (p->arg[0] == IND_CODE && t)
	{
		arg = get_ind_value(vm, p, 2);
//		arg = (short)get_magic(vm->map, p->pc + 2, 2);
	}
	if ((p->arg[0] == IND_CODE || p->arg[0] == DIR_CODE) && t)
	{
		p->reg[r] = arg;
		p->carry = 1;
		printf("P    %d | ld %d r%d\n", p->num, p->reg[r], r);
	}
	else
		p->carry = 0;
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}