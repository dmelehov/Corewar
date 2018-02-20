//
// Created by Dmitry Melehov on 2/19/18.
//

#include "../includes/vm.h"

static int 		set_ind_value(t_vm *vm, t_proc *p, int i)
{
	short int	ind;
	int 		shift;

	shift = calc_shift(p, p->cur_cmd, i);
	ind = get_magic(vm->map, p->pc + shift, 2);
	p->arg_v[i] = ind;
	return (1);
}

static int 		set_dir_value(t_vm *vm, t_proc *p, int i)
{
	int len;
	int shift;

	len = (g_op_tab[p->cur_cmd - 1].b2_dir == 0 ? 4 : 2);
	shift = calc_shift(p, p->cur_cmd, i);
	p->arg_v[i] = get_magic(vm->map, p->pc + shift, len);
	return (1);
}

static int 		set_reg_value(t_vm *vm, t_proc *p, int i)
{
	int r;

	r = vm->map[(p->pc + calc_shift(p, p->cur_cmd, i)) % MEM_SIZE];
	if (!(r > 0 && r <= REG_NUMBER))
		return (0);
	p->arg_v[i] = r;
	return (1);
}

static int 		get_argument(t_vm *vm, t_proc *p, int an)
{
	int a;

	a = p->arg[an];
	if (a == REG_CODE && !set_reg_value(vm, p, an))
		return (0);
	else if (a == DIR_CODE && !set_dir_value(vm, p, an))
		return (0);
	else if (a == IND_CODE && !set_ind_value(vm, p, an))
		return (0);
	return (1);
}

int		arg_checker(t_vm *vm, t_proc *p)
{
	int	i;
	int k;
	int l;
	int l1;

	i = 0;
	k = g_op_tab[p->cur_cmd - 1].arg_num;
	while (i < k)
	{
		l = g_op_tab[p->cur_cmd - 1].args[i];
		l1 = (1 << (p->arg[i] - 1));
		if (p->arg[i] != 0 && (l & l1) == l1)
		{
			if (!get_argument(vm, p, i))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}