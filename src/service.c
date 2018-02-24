//
// Created by Dmitry Melehov on 2/16/18.
//

#include "../includes/vm.h"

int 	get_arg_value(t_vm *vm, t_proc *p, int an)
{
	int adr;

	if (p->arg[an] == REG_CODE)
		return (p->reg[p->arg_v[an]]);
	else if (p->arg[an] == DIR_CODE)
	{
		if (vm->op_tab[p->cur_cmd].b2_dir)
			return ((short)p->arg_v[an]);
		return (p->arg_v[an]);
	}

	else if (p->arg[an] == IND_CODE)
	{
		if (p->cur_cmd != 13 && p->cur_cmd != 14)
			adr = p->pc + (p->arg_v[an] % IDX_MOD);
		else
			adr = p->pc + (p->arg_v[an] % MEM_SIZE);
		return (get_magic(vm->map, adr, 4));
	}
	return (p->arg[an]);
}

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
	return (res);
}

int	get_magic(unsigned char *s, int start, int len)
{
	int magic;
	int i;

	i = 0;
	magic = 0;
	if (start < 0)
		start += MEM_SIZE;
	while (i < len)
	{
		magic = (magic << 8);
		magic += s[(i + start) % MEM_SIZE];
		i++;
	}
	return (magic);
}

void	update_map(t_vm *vm, t_proc *p, int r, int adr)
{
	if (adr < 0)
		adr += MEM_SIZE;
	vm->map[(adr + 0) % MEM_SIZE] =
			(unsigned char)((p->reg[r] << 0) >> 24);
	vm->map[(adr + 1) % MEM_SIZE] =
			(unsigned char)((p->reg[r] << 8) >> 24);
	vm->map[(adr + 2) % MEM_SIZE] =
			(unsigned char)((p->reg[r] << 16) >> 24);
	vm->map[(adr + 3) % MEM_SIZE] =
			(unsigned char)((p->reg[r] << 24) >> 24);
	if (vm->cycles > PR_LIM)
	{
		printf("Updated map :\n");
		print_map_fragment(vm->map, adr, adr+6);
	}
}

void		set_args_data(t_vm *vm, t_proc *p)
{
	int i;

	i = (p->pc + 1) % MEM_SIZE;
	p->arg[0] = (vm->map[i] & 0xc0) >> 6;
	p->arg[1] = (vm->map[i] & 0x30) >> 4;
	p->arg[2] = (vm->map[i] & 0x0c) >> 2;
}


