//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

static	t_proc	*get_proc_copy(t_proc *pr, unsigned int start,int num)
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

void	op_fork(t_vm *vm, t_proc *p)
{
	t_proc	*p1;
	t_players *pl;
	short int adr;
	int i;

	pl = vm->pls;
	i = 0;
	while (pl && pl->turn != 1)
		pl = pl->next;
	p1 = pl->proc;
	while (p1 && ++i)
		p1 = p1->next;
	adr =  get_magic(vm->map, p->pc + 1, 2);
	p1 = get_proc_copy(p, adr, i + 1);
	p1->next = pl->proc;
	pl->proc = p1;
	ft_bzero(p->arg, 12);
	p->arg[0] = 2;
	printf("P    %d |fork (%d) %d\n", p->num, adr, p1->pc);
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}
