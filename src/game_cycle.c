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
//		ft_printf("{red|b}cycle == {%d}{eoc}\n", vm->cycles);
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
		pr->age += 1;
		if (pr->cur_cmd == 0)
			set_process_data(vm, pr);
		executor(vm, pr, vm->map[pr->pc]);
		pr = pr->next;
	}
}

static void    check_alive_proc(t_vm *vm, t_players *pl, t_proc *p) // Furkatos
{
	t_proc    *tmp;

	while (p && !p->is_alive)
	{
		printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
		p->num, p->age, vm->cycles_to_dye);
		tmp = p->next;
		free(p);
		p = tmp;
		vm->proc_alive -= 1;
	}
	pl->proc = p;
	while (p && p->next)
	{
		p->is_alive = 0;
		if (!p->next->is_alive)
		{
			printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				   p->next->num, p->next->age, vm->cycles_to_dye);
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


static void	kill_them_all(t_players *pl)
{
	t_proc *p;

	while (pl)
	{
		p = pl->proc;
		while (p)
		{
			p->is_alive = 0;
			p = p->next;
		}
		pl = pl->next;
	}
}

static void	live_manager(t_vm *vm, t_players *pl)
{
	if (vm->cycles_to_dye <= 0)
		kill_them_all(vm->pls);
	while (pl)
	{
		pl->live = 0;
		check_alive_proc(vm, pl, pl->proc);
		pl = pl->next;
	}
}

static void check_ctd(t_vm *vm, int *cnt)
{
	if (vm->live_amount < NBR_LIVE)
		(*cnt)++;
	if ((*cnt) == MAX_CHECKS || vm->live_amount >= NBR_LIVE)
	{
		vm->cycles_to_dye -= CYCLE_DELTA;
		printf("Cycle to die is now %d\n", vm->cycles_to_dye);
		(*cnt) = 0;
	}
	vm->live_amount = 0;
	vm->check += vm->cycles_to_dye;
}

void 	game_cycle(t_vm *vm)
{
	t_players *pl;
	int i;

	i = 0;
	while (vm->proc_alive > 0)
	{

		vm->cycles += 1;
		printf("%s %d\n", "It is now cycle", vm->cycles);
		if (vm->cycles == DEBUG)
		{
			srav();
//			print_map(vm->map);
		}
		pl = vm->pls;
		while (pl)
		{
			pl->turn = 1;
			game_processor(vm, pl);
			pl->turn = 0;
			pl = pl->next;
		}
		if (vm->cycles >= vm->check)
			live_manager(vm, vm->pls);
		if (vm->cycles_to_dye <= 0 || vm->cycles == GAME_LIM)
			break ;
		if (vm->cycles >= vm->check)
			check_ctd(vm, &i);
	}
}