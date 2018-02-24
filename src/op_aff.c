//
// Created by Dmitry Melehov on 2/14/18.
//

#include "../includes/vm.h"

void	op_aff(t_vm *vm, t_proc *p)
{
//	p->arg[0] = 1;
	if (arg_checker(vm, p))
	{
		;
//		ft_printf("%d\n", (p->arg_v[0] % 256));
	}
//	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 1)) % MEM_SIZE;
}
