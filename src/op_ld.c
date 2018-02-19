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
//	printf("Shift == %d\n", calc_shift(p, 2, 1));
	r = vm->map[(p->pc + calc_shift(p, 2, 1)) % MEM_SIZE];
	t = (r > 0 && r <= REG_NUMBER);
	if (p->arg[0] == DIR_CODE && t)
		arg = get_magic(vm->map, p->pc + 2, 4);
	else if (p->arg[0] == IND_CODE && t)
	{
		arg = get_ind_value(vm, p, 2);
		arg = get_magic(vm->map, arg, 4);
//		arg = arg % IDX_MOD;
//		arg = arg % MEM_SIZE;
//		printf("ARG == %d\n", arg);
//		print_map_fragment(vm->map, 73, 78);
	}
	if ((p->arg[0] == IND_CODE || p->arg[0] == DIR_CODE) && t)
	{
		p->reg[r] = arg;
		p->carry = (arg == 0 ? 1 : 0);
//		p->carry = (p->carry == 0 ? 1 : 0);
		printf("P    %d | ld %d r%d\n", p->num, p->reg[r], r);
	}
//	else
//		p->carry = 0;
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}