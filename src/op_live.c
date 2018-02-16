//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

void	op_live(t_vm *vm, t_proc *p)
{
	int	arg;
	t_players	*pl;

	arg = get_magic(vm->map, p->pc + 1, 4);
	pl = vm->pls;
	while (pl)
	{
		if (pl->num == arg)
		{
			printf("SRAV_ALIVE!!!\n");
			pl->live++;
		}
		else
			pl->live = 0;
		pl = pl->next;
	}
	printf("P    %d | live %d\n", p->num, arg);
	ft_bzero(p->arg, 12);
	p->arg[0] = 2;
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}

