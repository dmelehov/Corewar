//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_st(t_vm *vm, t_proc *p)
{
	int r[4];
	int adr;

	set_args_data(vm, p);
	r[0] = (vm->map[(p->pc + 2) % MEM_SIZE]);
	r[1] = (vm->map[(p->pc + 3) % MEM_SIZE]);
	r[2] = (r[0] > 0 && r[0] <= REG_NUMBER);
	r[3] = (r[1] > 0 && r[1] <= REG_NUMBER);
	if (p->arg[0] == REG_CODE && p->arg[1] == REG_CODE
		&& r[2] && r[3])
	{
		p->reg[r[1]] = p->reg[r[0]];
		adr = r[1];
	}
	else if (p->arg[0] == REG_CODE && p->arg[1] == IND_CODE
			 && r[2])
	{
		adr = get_ind_value(vm, p, 3);
		update_map(vm, p, r[0], adr);
		adr -= p->pc;
	}
	printf("P    %d | st r%d %d\n", p->num, r[0], adr);
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}