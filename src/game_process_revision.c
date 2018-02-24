/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process_revision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:00:25 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:10:39 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		check_list_tail(t_vm *vm, t_proc *p)
{
	t_proc	*tmp;

	while (p && !p->is_alive)
	{
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
			p->num, p->age, vm->cycles_to_die);
		tmp = p->next;
		free(p);
		p = tmp;
		vm->proc_alive -= 1;
	}
	vm->proc = p;
}

static void		check_alive_proc(t_vm *vm, t_proc *p)
{
	t_proc	*tmp;

	tmp = NULL;
	while (p && p->next)
	{
		p->is_alive = 0;
		if (!p->next->is_alive)
		{
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				p->next->num, p->next->age, vm->cycles_to_die);
			tmp = p->next->next;
			free(p->next);
			p->next = tmp;
			vm->proc_alive -= 1;
		}
		else
			p = p->next;
	}
	if (p)
		p->is_alive = 0;
}

static void		kill_them_all(t_proc *p)
{
	while (p)
	{
		p->is_alive = 0;
		p = p->next;
	}
}

void			live_manager(t_vm *vm, t_players *pl)
{
	if (vm->cycles_to_die <= 0)
		kill_them_all(vm->proc);
	check_list_tail(vm, vm->proc);
	check_alive_proc(vm, vm->proc);
	while (pl)
	{
		pl->live = 0;
		pl = pl->next;
	}
}

void			check_cycles_to_die(t_vm *vm, int *cnt)
{
	if (vm->live_amount < NBR_LIVE)
		(*cnt)++;
	if ((*cnt) == MAX_CHECKS || vm->live_amount >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
		(*cnt) = 0;
		vm->live_amount = 0;
	}
	vm->live_amount = 0;
	vm->check += vm->cycles_to_die;
}
