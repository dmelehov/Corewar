//
// Created by Dmitry Melehov on 2/14/18.
//

#include "../includes/vm.h"



static void	update_map2(t_vm *vm, t_proc *p, int r, int adr)
{
	adr += p->pc;
	if (adr < 0)
		adr += MEM_SIZE;
	printf("P %d store adr == {%d}\n",p->num, adr );
	vm->map[(adr + 0) % MEM_SIZE] = (p->reg[r] << 0) >> 24;
	vm->map[(adr + 1) % MEM_SIZE] = (p->reg[r] << 8) >> 24;
	vm->map[(adr + 2) % MEM_SIZE] = (p->reg[r] << 16) >> 24;
	vm->map[(adr + 3) % MEM_SIZE] = (p->reg[r] << 24) >> 24;
	print_map_fragment(vm->map, adr-5, adr + 10);
}





void	op_and(t_vm *vm, t_proc *p)
{
	;
}

void	op_or(t_vm *vm, t_proc *p)
{
	;
}

void	op_xor(t_vm *vm, t_proc *p)
{
	;
}



void	op_ldi(t_vm *vm, t_proc *p)
{
	;
}

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

static	int get_sti_arg_1(t_vm *vm, t_proc *p)
{
	int r;

	r = 0;
	if (p->arg[1] == REG_CODE)
	{
//		printf("SRAV2\n");
		r = vm->map[(p->pc + 3) % MEM_SIZE] - 1;
		if (r >= 0 && r < REG_SIZE)
		{
//			printf("SRAV\n");
			return (p->reg[r]);
		}

	}
	else if (p->arg[1] == DIR_CODE)
		return (get_magic(vm->map, p->pc + 3, 2));
	else if (p->arg[1] == IND_CODE)
		return ((get_magic(vm->map, p->pc + 3, 2) % IDX_MOD));
	return (r);
}

void	op_sti(t_vm *vm, t_proc *p)
{
	int r[3];
	int pos;

	r[0] = vm->map[(p->pc + 2) % MEM_SIZE] - 1;
	if (check_sti_args(p))
	{
		print_map_fragment(vm->map, p->pc, p->pc + 6);
		r[1] = get_sti_arg_1(vm, p);
//		pos = (p->arg[1] == 3 ? 3 : 3);
//		r[1] = get_magic(&vm->map[p->pc + 3], p->arg[1]);
		pos = (p->arg[1] == 1 ? 1 : 2);
		r[2] = get_magic(vm->map, p->pc + 3 + pos, p->arg[2]);
		update_map2(vm, p, r[0], (r[1] + r[2]) % MEM_SIZE);
		printf("STI == {r%d|%d|%d}\n", r[0] + 1, r[1], r[2]);
	}
	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
}




void	op_lld(t_vm *vm, t_proc *p)
{
	;
}

void	op_lldi(t_vm *vm, t_proc *p)
{
	;
}

void	op_lfork(t_vm *vm, t_proc *p)
{
	;
}

void	op_aff(t_vm *vm, t_proc *p)
{
	;
}
