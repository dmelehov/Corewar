/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:19:10 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:32:18 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_live(t_vm *vm, t_proc *p)
{
	int			arg;
	t_players	*pl;

	arg = get_magic(vm->map, p->pc + 1, 4);
	pl = vm->pls;
	p->is_alive += 1;
	p->age = 0;
	vm->live_amount += 1;
	if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 4) == 4)
		ft_printf("P %4d | live %d\n", p->num, arg);
	while (pl)
	{
		if (pl->num == arg)
		{
			pl->live++;
			pl->llc = vm->cycles;
			vm->winner = pl;
			if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 1) == 1)
				ft_printf("Player %d (%s) is said to be alive\n",
					PL_NUM - pl->num + 1, pl->header->prog_name);
		}
		pl = pl->next;
	}
	p->arg[0] = 2;
}
