//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_zjmp(t_vm *vm, t_proc *p)
{
	short int ind;
	char *s;

	s = "FAILED";
	p->arg[0] = 2;
	ind = (short)(get_magic(vm->map, p->pc + 1, 2));
	if (p->carry == 1)
	{
		s = "OK";
		p->pc = (p->pc + (ind % IDX_MOD)) % MEM_SIZE;
		if (p->pc < 0)
			p->pc += MEM_SIZE;
	}
	else
		p->pc = (p->pc + calc_shift(p, p->cur_cmd, 1)) % MEM_SIZE;
	printf("P%5d | zjmp %d %s\n", p->num, ind, s);
}