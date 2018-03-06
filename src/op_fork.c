/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:17:04 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:31:30 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static	t_proc	*get_proc_copy(t_vm *vm, t_proc *pr, int start)
{
	t_proc	*p;
	t_proc	*tmp;

	tmp = vm->proc;
	p = (t_proc *)ft_malloc_s(1, sizeof(t_proc));
	ft_memcpy(p, pr, sizeof(t_proc));
	vm->mpn += 1;
	p->num = vm->mpn;
	p->pc = (p->pc + (start % IDX_MOD)) % MEM_SIZE;
	if (p->pc < 0)
		p->pc += MEM_SIZE;
	vm->proc_alive += 1;
	p->cur_cmd = 0;
	vm->proc = p;
	p->next = tmp;
	return (p);
}

void			op_fork(t_vm *vm, t_proc *p)
{
	t_players *pl;
	short int adr;

	p->arg[0] = 2;
	pl = vm->pls;
	while (pl && pl->turn != 1)
		pl = pl->next;
	adr = (short)get_magic(vm->map, p->pc + 1, 2);
	get_proc_copy(vm, p, adr);
	if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 4) == 4)
		ft_printf("P %4d | fork %d (%d)\n", p->num, adr, p->pc + adr % IDX_MOD);
}
