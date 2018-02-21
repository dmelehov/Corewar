//
// Created by Dmitry Melehov on 2/13/18.
//

#include "../includes/vm.h"

static void	srav()
{
	;
}

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
		ft_printf("{red|b}cycle == {%d}{eoc}\n", vm->cycles);
		if (vm->cycles > PR_LIM && ft_printf("{green|b}Before cmd{eoc}\n"))
			print_proc_struct(p);
		if (vm->cycles == DEBUG)
			srav();
		vm->op[i](vm, p);
		if (vm->cycles > PR_LIM && ft_printf("{blue|b}After cmd{eoc}\n"))
			print_proc_struct(p);
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
		p->wait = g_op_tab[i - 1].cost;
		p->cur_cmd = g_op_tab[i - 1].opcode;
		set_args_data(vm, p);
	}
}

static void	game_processor(t_vm *vm, t_players *pl)
{
	t_proc	*pr;

	pr = pl->proc;
	while (pr)
	{
		if (pr->cur_cmd == 0)
			set_process_data(vm, pr);
		executor(vm, pr, vm->map[pr->pc]);
		pr = pr->next;
	}
}

static void	check_alive_proc(t_vm *vm, t_players *pl, t_proc *p)
{
	t_proc	*prev;
	t_proc	*tmp;
	int i;

	i = 0;
	prev = p;
	while (p)
	{
		tmp = p->next;
		if (!p->is_alive)
		{
			if (i == 0)
				pl->proc = p->next;
			else
				prev->next = p->next;
			vm->proc_alive -= 1;
//			free(p);
		}
		else
			p->is_alive = 0;
		p = tmp;
		if (i++ != 0)
			prev = prev->next;
	}
}

static void	live_manager(t_vm *vm, t_players *pl, int *cnt)
{
	if ((*cnt) == MAX_CHECKS || vm->live_amount >= NBR_LIVE)
	{
		vm->cycles_to_dye -= CYCLE_DELTA;
		(*cnt) = 0;
	}
	if (vm->live_amount < NBR_LIVE)
		(*cnt)++;
	vm->live_amount = 0;
	while (pl)
	{
		pl->live = 0;
		check_alive_proc(vm, pl, pl->proc);
		pl = pl->next;
	}
}

void 	game_cycle(t_vm *vm)
{
	t_players *pl;
	int i;

	i = 0;
	while (vm->cycles_to_dye > 0 && vm->proc_alive > 0)
	{
		vm->cycles += 1;
		if (vm->cycles == DEBUG)
			srav();
		if (vm->cycles % vm->cycles_to_dye == 0)
		{
			live_manager(vm, vm->pls, &i);
		}
		pl = vm->pls;
		while (pl)
		{
			pl->turn = 1;
			game_processor(vm, pl);
			pl->turn = 0;
			pl = pl->next;
		}
		if (vm->cycles == GAME_LIM)
			break ;
	}
}