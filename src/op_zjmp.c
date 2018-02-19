//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_zjmp(t_vm *vm, t_proc *p)
{
	short int ind;
	char *s;

	print_map_fragment(vm->map, p->pc, p->pc + 7);
	ind = (get_magic(vm->map, p->pc + 1, 2) /*% MEM_SIZE*/);
//	printf("IND==%d\n", ind);
	if (p->carry == 1)
	{
		p->pc = (p->pc + ind) % MEM_SIZE;
		if (p->pc < 0)
			p->pc += MEM_SIZE;
		s = "OK";
		printf("Jumped to : \n");
		print_map_fragment(vm->map, p->pc, p->pc + 12);
//		if (p->num == 6 && vm->cycles == 2830)
//			print_map(vm->map);
	}
	else
	{
		s = "FAILED";
		ft_bzero(p->arg, 12);
		p->arg[0] = 2;
		p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
	}
	printf(" P %d |zjmp %d %s\n", p->num, ind, s);
}