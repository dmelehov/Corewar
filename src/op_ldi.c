//
// Created by Dmitry Melehov on 2/18/18.
//

#include "../includes/vm.h"

void	op_ldi(t_vm *vm, t_proc *p)
{
	int argv[3];

	if (arg_checker(vm, p))
	{
		argv[0] = get_arg_value(vm, p, 0);
		argv[1] = get_arg_value(vm, p, 1);
		argv[2] = (short)((argv[0] + argv[1]) % IDX_MOD);
		p->reg[p->arg_v[2]] = get_magic(vm->map, p->pc + argv[2], 4);
		printf("P%5d | ldi %d %d r%d\n", p->num, argv[0], argv[1], p->arg_v[2]);
		printf("       | -> load from %d + %d = %d ", argv[0], argv[1], argv[0] + argv[1]);
		printf("(with pc and mod %d)\n", p->pc + argv[2]);
	}
}

