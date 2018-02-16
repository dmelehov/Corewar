//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_zjmp(t_vm *vm, t_proc *p)
{
	int ind;

	print_map_fragment(vm->map, p->pc, p->pc + 6);
//	ind = get_ind_value(vm, p, 1);
	ind = (get_magic(vm->map, p->pc + 1, 2) % MEM_SIZE);
	if (p->carry == 1)
	{
		p->pc = (p->pc + ind) % MEM_SIZE;
		if (p->pc < 0)
			p->pc = MEM_SIZE + p->pc;
		printf("Jumped to : \n");
		print_map_fragment(vm->map, p->pc, p->pc + 6);
	}
	else
	{
		ft_bzero(p->arg, 12);
		p->arg[0] = 2;
		p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
	}
	printf(" P %d |zjmp %d OK\n", p->num, ind);
}