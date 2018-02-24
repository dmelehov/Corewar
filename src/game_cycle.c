//
// Created by Dmitry Melehov on 2/13/18.
//

#include "../includes/vm.h"

static void	srav()
{
	;
}

static void    check_alive_proc(t_vm *vm, t_proc *p) // Furkatos
{
	t_proc    *tmp;

	while (p && !p->is_alive)
	{
		printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
		p->num, p->age, vm->cycles_to_die);
		tmp = p->next;
		free(p);
		p = tmp;
		vm->proc_alive -= 1;
	}
	vm->proc = p;
	while (p && p->next)
	{
		p->is_alive = 0;
		if (!p->next->is_alive)
		{
			printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
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

static void	kill_them_all(t_proc *p)
{
	while (p)
	{
		p->is_alive = 0;
		p = p->next;
	}
}

static void	live_manager(t_vm *vm, t_players *pl)
{
	if (vm->cycles_to_die <= 0)
		kill_them_all(vm->proc);
	check_alive_proc(vm, vm->proc);
	while (pl)
	{
		pl->live = 0;
		pl = pl->next;
	}
}

static void check_ctd(t_vm *vm, int *cnt)
{
	if (vm->live_amount < NBR_LIVE)
		(*cnt)++;
	if ((*cnt) == MAX_CHECKS || vm->live_amount >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		printf("Cycle to die is now %d\n", vm->cycles_to_die);
		(*cnt) = 0;
		vm->live_amount = 0;
	}
	vm->live_amount = 0;
	vm->check += vm->cycles_to_die;
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
		set_args_data(vm, p);
		if (vm->cycles == DEBUG)
			srav();
		vm->op[i](vm, p);
		if (i != 9)
			p->pc = (p->pc + calc_shift(p, i, vm->op_tab[i].arg_num)) % MEM_SIZE;
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

static void	game_processor(t_vm *vm, t_proc *pr)
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
void 	game_cycle(t_vm *vm)
{
	int i;

	i = 0;
	while (vm->proc_alive > 0)
	{
		vm->cycles += 1;
		printf("It is now cycle %d\n", vm->cycles);
		if (vm->cycles == DEBUG)
		{
			print_map(vm->map);
			srav();
		}
		game_processor(vm, vm->proc);
		if (vm->cycles >= vm->check)
		{
			live_manager(vm, vm->pls);
			check_ctd(vm, &i);
		}
		if (vm->cycles == GAME_LIM)
			break ;
	}
}