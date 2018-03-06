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
	int	pc;

	pc = p->pc;
	if (p->wait != 0)
	{
		p->wait -= 1;
		if (p->wait != 0)
			return ;
	}
	if (i != 9 && vm->flags->n)
		del_proc(p);
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
	if_jump_flag(vm, pc, p->pc, i);
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

static void		flag_mngr(t_vm *vm)
{
	char	*line;

	if (vm->flags->n)
	{
		visualize(vm);
		return ;
	}
	if (vm->flags->d != -1 && vm->flags->d == vm->cycles)
	{
		print_map(vm->map);
		exit(0);
	}
	if (vm->flags->s != -1 && !(vm->cycles % vm->flags->s))
	{
		print_map(vm->map);
		get_next_line(0, &line);
		ft_strdel(&line);
	}
}

void			game_cycle(t_vm *vm)
{
	int	i;

	i = 0;
	if (!vm->flags->n)
		print_intro(vm);
	while (vm->proc_alive > 0)
	{
		flag_mngr(vm);
		vm->cycles += 1;
		if (!vm->flags->n && vm->flags->v != -1 && (vm->flags->v & 2) == 2)
			ft_printf("It is now cycle %d\n", vm->cycles);
		game_processor(vm, vm->proc);
		if (vm->cycles >= vm->check)
		{
			live_manager(vm, vm->pls);
			check_cycles_to_die(vm, &i);
		}
	}
}
