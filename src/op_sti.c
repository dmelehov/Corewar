//
// Created by Dmitry Melehov on 2/17/18.
//

#include "../includes/vm.h"

void	op_sti(t_vm *vm, t_proc *p)
{
	int argv[3];

	if (arg_checker(vm, p))
	{
		argv[1] = get_arg_value(vm, p, 1);
		argv[2] = get_arg_value(vm, p, 2);
		argv[0] = ((argv[1] + argv[2]) % IDX_MOD);
		update_map(vm, p, p->arg_v[0], p->pc + argv[0]);
		printf("P    %d | sti r%d %d %d\n", p->num,
			   p->arg_v[0], argv[1], argv[2]);
		printf("        | -> store  to %d + %d = %d ",
			   argv[1], argv[2], argv[0]);
		printf("(with pc and mod %d)\n", p->pc + argv[0]);
	}
	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 3)) % MEM_SIZE;
}
