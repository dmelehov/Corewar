//
// Created by Dmitry Melehov on 2/17/18.
//

#include "../includes/vm.h"



static	int check_sti_args(t_proc *p)
{
	if (p->arg[0] != REG_CODE)
		return (0);
	if (p->arg[1] != REG_CODE && p->arg[1] != DIR_CODE && p->arg[1] != IND_CODE)
		return (0);
	if (p->arg[2] != REG_CODE && p->arg[2] != DIR_CODE)
		return (0);
	return (1);
}

static	int get_sti_arg_2(t_vm *vm, t_proc *p)
{
	int r;
	int shift;

	r = 0;
	shift = calc_shift(p, p->cur_cmd, 2);
	if (p->arg[2] == REG_CODE)
		r = p->reg[vm->map[(p->pc + shift) % MEM_SIZE]];
	else
		r = (short)get_magic(vm->map, p->pc + shift, 2);
	return (r);
}

static	int get_sti_arg_1(t_vm *vm, t_proc *p)
{
	int r;

	r = 0;
	if (p->arg[1] == REG_CODE)
		r = p->reg[vm->map[(p->pc + 3) % MEM_SIZE]];
	else if (p->arg[1] == DIR_CODE)
		r = (short)get_magic(vm->map, p->pc + 3, 2);
	else
		r = get_magic(vm->map, p->pc + 3, 4);
	return (r);
}

void	op_sti(t_vm *vm, t_proc *p)
{
	int r[3];
	int ind;
	int t;

	r[0] = vm->map[(p->pc + 2) % MEM_SIZE];
	t = (r[0] > 0 && r[0] <= REG_NUMBER);
	if (check_sti_args(p) && t)
	{
		print_map_fragment(vm->map, p->pc, p->pc + 7);
		r[1] = get_sti_arg_1(vm, p);
		r[2] = get_sti_arg_2(vm, p);
		if (p->arg[1] == 3)
			ind = (short)((r[1] + r[2]) % IDX_MOD);
		else
			ind = (r[1] + r[2]) % MEM_SIZE;
		ind = ind % MEM_SIZE;
//		printf("Stored value on map is:\n");
//		print_map_fragment(vm->map, ind + p->pc - 2, ind + p->pc + 6);
		printf("P    %d | sti r%d %d %d\n", p->num, r[0], r[1], r[2]);
		printf("        | -> store  to %d + %d = %d ", r[1], r[2], ind);
		printf("(with pc and mod %d)\n", p->pc + ind);
		ind += p->pc;
		if (ind < 0)
			ind += MEM_SIZE;
//		printf("IND == %d\n", ind);
		update_map(vm, p, r[0], ind);
//		printf("STI == {r%d|%d|%d|%d|%d}\n", r[0], r[1], r[2], ind, p->pc + ind);
	}
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}