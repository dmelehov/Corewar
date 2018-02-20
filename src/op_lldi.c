//
// Created by Dmitry Melehov on 2/18/18.
//

#include "../includes/vm.h"

void	op_lldi(t_vm *vm, t_proc *p)
{
	int argv[3];

	if (arg_checker(vm, p))
	{
		argv[0] = get_arg_value(vm, p, 0);
		argv[1] = get_arg_value(vm, p, 1);
		argv[2] = ((argv[0] + argv[1]) % MEM_SIZE);
		p->reg[p->arg_v[2]] = get_magic(vm->map, p->pc + argv[2], 4);
		printf("P    %d | lldi %d %d r%d\n", p->num, argv[0], argv[1], p->arg_v[2]);
		printf("        | -> load from %d + %d = %d ", argv[0], argv[1], argv[2]);
		printf("(with pc and mod %d)\n", p->pc + argv[2]);

	}
	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 3)) % MEM_SIZE;
}