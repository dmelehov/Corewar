/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:02:00 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:27:12 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		executor(t_vm *vm, t_proc *p, int i)
{
	if (p->wait != 0)
	{
		p->wait -= 1;
		if (p->wait != 0)
			return ;
	}
	if (i > 0 && i < 17)
	{
		set_args_data(vm, p);
		vm->op[i](vm, p);
		if (i != 9)
			p->pc = (p->pc +
				calc_shift(vm, p, vm->op_tab[i].arg_num)) % MEM_SIZE;
	}
	else
		p->pc = (p->pc + 1) % MEM_SIZE;
	p->cur_cmd = 0;
	ft_bzero(p->arg, 12);
	ft_bzero(p->arg_v, 12);
}

static void		set_process_data(t_vm *vm, t_proc *p)
{
	int	i;

	i = vm->map[p->pc];
	if (p->wait != 0)
		return ;
	else if (i > 0 && i < 17)
	{
		p->wait = vm->op_tab[i].cost;
		p->cur_cmd = vm->op_tab[i].opcode;
	}
}

static void		game_processor(t_vm *vm, t_proc *pr)
{
	while (pr)
	{
		pr->age += 1;
		if (pr->cur_cmd == 0)
			set_process_data(vm, pr);
		executor(vm, pr, pr->cur_cmd);
		pr = pr->next;
	}
}

void			game_cycle(t_vm *vm)
{
	int	i;

	i = 0;
	while (vm->proc_alive > 0)
	{
		vm->cycles += 1;
		ft_printf("It is now cycle %d\n", vm->cycles);
		game_processor(vm, vm->proc);
		if (vm->cycles >= vm->check)
		{
			live_manager(vm, vm->pls);
			check_cycles_to_die(vm, &i);
		}
	}
}
