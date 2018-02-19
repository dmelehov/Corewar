//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

int		calc_shift(t_proc *p, int cmd, int max_i)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (i < 3 && i < max_i)
	{
		if (p->arg[i] == 1)
			res += 1;
		else if (p->arg[i] == 2)
			res += (g_op_tab[cmd - 1].b2_dir == 0 ? 4 : 2);
		else if (p->arg[i] == 3)
			res += 2;
		i++;
	}
	res += g_op_tab[cmd - 1].arg_len + 1;
//	printf(" Max_shift == {%d}\n", res);
	return (res);
}

int		move_carret(t_proc *p, int cmd)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (i < 3)
	{
		if (p->arg[i] == 1)
			res += 1;
		else if (p->arg[i] == 2)
			res += (g_op_tab[cmd - 1].b2_dir == 0 ? 4 : 2);
		else if (p->arg[i] == 3)
			res += 2;
		i++;
	}
	res += g_op_tab[cmd - 1].arg_len + 1;
	printf(" ADV {%d}\n", res);
	return (res);
}

//

int	get_magic(unsigned char *s, int start, int len)
{
	int magic;
	int i;

	i = 0;
	magic = 0;
	while (i < len)
	{
		magic = (magic << 8);
		magic += s[(i + start) % MEM_SIZE];
		i++;
	}
	return (magic);
}

int		get_ind_value(t_vm *vm, t_proc *p, int pos)
{
	int	adr;
	int ind;

	ind = (short)get_magic(vm->map, p->pc + pos, 2);
//	printf("ind == %d\n", ind);
//	printf("ind == %d\n", (short)ind);
	adr = p->pc + (ind % IDX_MOD);
	if (adr < 0)
		adr += MEM_SIZE;
	printf("ADR == %d\n", adr);
	return (adr);
}

void	update_map(t_vm *vm, t_proc *p, int r, int adr)
{
	vm->map[(adr + 0) % MEM_SIZE] = (p->reg[r] << 0) >> 24;
	vm->map[(adr + 1) % MEM_SIZE] = (p->reg[r] << 8) >> 24;
	vm->map[(adr + 2) % MEM_SIZE] = (p->reg[r] << 16) >> 24;
	vm->map[(adr + 3) % MEM_SIZE] = (p->reg[r] << 24) >> 24;
	printf("Updated map :\n");
	print_map_fragment(vm->map, adr, adr+6);
}

void		set_args_data(t_vm *vm, t_proc *p)
{
	int i;

	i = (p->pc + 1) % MEM_SIZE;
	p->arg[0] = (vm->map[i] & 0xc0) >> 6;
	p->arg[1] = (vm->map[i] & 0x30) >> 4;
	p->arg[2] = (vm->map[i] & 0x0c) >> 2;
}


