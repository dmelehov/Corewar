//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

static	t_proc	*get_proc_copy(t_proc *pr, unsigned int start)
{
	t_proc	*p;

	p = (t_proc *)ft_malloc_s(1, sizeof(t_proc));
	ft_memcpy(p, pr, sizeof(t_proc));
	p->num = pr->num + 1;
	p->pc = start;
	p->cur_cmd = 0;
	return (p);
}

void	op_fork(t_vm *vm, t_proc *p)
{
	t_proc	*p1;
	t_players *pl;
	unsigned int adr;

	pl = vm->pls;
	while (pl && pl->turn != 1)
		pl = pl->next;
	adr = ((p->pc + get_magic(vm->map, p->pc + 1, 2)) % MEM_SIZE);
	p1 = get_proc_copy(p, adr);
	p1->next = pl->proc;
	pl->proc = p1;
	ft_bzero(p->arg, 12);
	p->arg[0] = 2;
	printf(" P %d |fork %d (%d) OK\n", p->num, adr - p->pc, adr);
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}
