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
	p->is_alive += 1;
	p->age = 0;
	vm->live_amount += 1;
	printf("P%5d | live %d\n", p->num, arg);
	while (pl)
	{
		if (pl->num == arg)
		{
			pl->live++;
			pl->llc = vm->cycles;
			vm->winner = pl;
			printf("Player %d (%s) is said to be alive\n",
				   PL_NUM - pl->num + 1, pl->header->prog_name);
		}
		pl = pl->next;
	}
	p->arg[0] = 2;
//	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 1)) % MEM_SIZE;
}

