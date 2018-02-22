//
// Created by Dmitry Melehov on 2/20/18.
//

#include "../includes/vm.h"

static	t_proc	*get_proc_copy(t_proc *pr, int start,int num)
{
	t_proc	*p;

	p = (t_proc *)ft_malloc_s(1, sizeof(t_proc));
	ft_memcpy(p, pr, sizeof(t_proc));
	p->num = num;
	p->pc = ((p->pc + start) % MEM_SIZE);
	if (p->pc < 0)
		p->pc += MEM_SIZE;
	p->cur_cmd = 0;
	return (p);
}

void	op_lfork(t_vm *vm, t_proc *p)
{
	t_proc	*p1;
	t_players *pl;
	int adr;

	p->arg[0] = 2;
	pl = vm->pls;
	while (pl && pl->turn != 1)
		pl = pl->next;
	adr = (short)get_magic(vm->map, p->pc + 1, 2);
	pl->mpn += 1;
	p1 = get_proc_copy(p, adr, pl->mpn);
	p1->next = pl->proc;
	pl->proc = p1;
	vm->proc_alive += 1;
	printf("P%5d | lfork %d (%d)\n", p->num, adr, p->pc + adr);
	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 1)) % MEM_SIZE;
}