//
// Created by Dmitry Melehov on 2/13/18.
//

#include "../includes/vm.h"

static void		get_command_data(t_vm *vm, int i, t_proc *p)
{
	p->cur_cmd = g_op_tab[i - 1].opcode;
	p->wait = g_op_tab[i - 1].cost;
	p->arg[0] = (vm->map[p->pc + 1] & 0xc0) >> 6;
	p->arg[1] = (vm->map[p->pc + 1] & 0x30) >> 4;
	p->arg[2] = (vm->map[p->pc + 1] & 0x0c) >> 2;
}

static void		get_process_data(t_vm *vm, t_proc *p)
{
	if (vm->map[p->pc] < 16 && vm->map[p->pc] > 0)
		get_command_data(vm, vm->map[p->pc], p);
}

static void	game_processor(t_vm *vm, t_players *pl)
{
	t_proc	*pr;

	pr = pl->proc;
	while (pr)
	{
		get_process_data(vm, pr);
		pr = pr->next;
	}
}

void 	game_cycle(t_vm *vm)
{
	t_players *pl;

	while (vm->cycles_to_dye && vm->no_one_alive != 1)
	{
		pl = vm->pls;
		while (pl)
		{
			game_processor(vm, pl);
			pl = pl->next;
		}
		vm->cycles += 1;
		vm->cycles_to_dye -= 1;
		if (vm->cycles == 10)
			break ;
	}
}