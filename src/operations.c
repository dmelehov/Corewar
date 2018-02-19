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
