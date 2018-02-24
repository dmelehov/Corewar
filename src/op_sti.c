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
//		if (p->arg[1] == 1)
//			argv[1] = get_arg_value(vm, p, 1);
//		else
//			argv[1] = (short)get_arg_value(vm, p, 1);
//		if (p->arg[2] == 1)
//			argv[2] = get_arg_value(vm, p, 2);
//		else
//			argv[2] = (short)get_arg_value(vm, p, 2);
		argv[0] = (short)((argv[1] + argv[2]) % IDX_MOD);
		printf("P%5d | sti r%d %d %d\n", p->num,
			   p->arg_v[0], argv[1], argv[2]);
		printf("       | -> store to %d + %d = %d ",
			   argv[1], argv[2], argv[1] + argv[2]);
		printf("(with pc and mod %d)\n", p->pc + argv[0]);
		update_map(vm, p, p->arg_v[0], p->pc + argv[0]);
	}
}
