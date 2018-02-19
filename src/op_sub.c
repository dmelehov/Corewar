//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_sub(t_vm *vm, t_proc *p)
{
	unsigned int	r[3];

	r[0] = vm->map[(p->pc + 2) % MEM_SIZE];
	r[1] = vm->map[(p->pc + 3) % MEM_SIZE];
	r[2] = vm->map[(p->pc + 4) % MEM_SIZE];
	if (p->arg[0] == 1 && p->arg[1] == 1
		&& r[0] <= 16 && r[1] <= 16 && r[2] <= 16
		&& r[0] > 0 && r[1] > 0 && r[2] > 0)
	{
		p->reg[r[2]] = p->reg[r[0]] - p->reg[r[1]];
//		p->carry = 1;
	}
//	else
//		p->carry = 0;
	p->carry = (p->carry == 0 ? 1 : 0);
	printf("P %d | sub r%d r%d r%d\n", p->num, r[0], r[1], r[2]);
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}