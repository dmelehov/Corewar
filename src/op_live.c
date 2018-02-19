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
	printf("P    %d | live %d\n", p->num, arg);
	while (pl)
	{
		if (pl->num == arg)
		{
			pl->live++;
			pl->llc = vm->cycles;
			printf("Player %d (%s) is said to be alive\n",
				   PL_NUM - pl->num + 1, pl->header->prog_name);
		}
		else
			pl->live = 0;
		pl = pl->next;
	}

	ft_bzero(p->arg, 12);
	p->arg[0] = 2;
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}

