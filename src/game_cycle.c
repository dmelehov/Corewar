//
// Created by Dmitry Melehov on 2/13/18.
//

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
		ft_printf("{red|b}cycle == {%d}{eoc}\n", vm->cycles);
		if (vm->cycles > PR_LIM && ft_printf("{green|b}Before cmd{eoc}\n"))
			print_proc_struct(p);
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
		if (!pr->cur_cmd)
			set_process_data(vm, pr);
		executor(vm, pr, vm->map[pr->pc]);
		pr = pr->next;
	}
}

void 	game_cycle(t_vm *vm)
{
	t_players *pl;

	while (vm->cycles_to_dye && vm->proc_alive)
	{
		vm->cycles += 1;
		if (vm->cycles % vm->cycles_to_dye == 0)
		{
			vm->cycles_to_dye -= CYCLE_DELTA;
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