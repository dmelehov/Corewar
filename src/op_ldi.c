//
// Created by Dmitry Melehov on 2/18/18.
//

#include "../includes/vm.h"

void	op_ldi(t_vm *vm, t_proc *p)
{
	int argv[3];

	if (arg_checker(vm, p))
	{
		argv[0] = get_arg_value(vm, p, 0);
		argv[1] = get_arg_value(vm, p, 1);
		argv[2] = (short)((argv[0] + argv[1]) % IDX_MOD);
		p->reg[p->arg_v[2]] = get_magic(vm->map, p->pc + argv[2], 4);
		printf("P    %d | ldi %d %d r%d\n", p->num, argv[0], argv[1], p->arg_v[2]);
		printf("        | -> load from %d + %d = %d ", argv[0], argv[1], argv[2]);
		printf("(with pc and mod %d)\n", p->pc + argv[2]);

	}
	p->pc = (p->pc + calc_shift(p, p->cur_cmd, 3)) % MEM_SIZE;
}

//static	int check_ldi_args(t_proc *p)
//{
//	if (p->arg[0] != REG_CODE && p->arg[0] != DIR_CODE && p->arg[0] != IND_CODE)
//		return (0);
//	if (p->arg[1] != REG_CODE && p->arg[1] != DIR_CODE)
//		return (0);
//	if (p->arg[2] != REG_CODE)
//		return (0);
//	return (1);
//}
//
//static	int get_ldi_arg_2(t_vm *vm, t_proc *p)
//{
//	int r;
//	int shift;
//
//	r = 0;
//	shift = calc_shift(p, p->cur_cmd, 1);
//	if (p->arg[1] == REG_CODE)
//		r = p->reg[vm->map[(p->pc + shift) % MEM_SIZE]];
//	else
//		r = (short)get_magic(vm->map, p->pc + shift, 2);
//	return (r);
//}
//
//static	int get_ldi_arg_1(t_vm *vm, t_proc *p)
//{
//	int r;
//
//	r = 0;
//	if (p->arg[0] == REG_CODE)
//		r = p->reg[vm->map[(p->pc + 2) % MEM_SIZE]];
//	else if (p->arg[0] == DIR_CODE)
//		r = (short)get_magic(vm->map, p->pc + 2, 2);
//	else
//	{
//		r = get_ind_value(vm, p , 2);
//		r = get_magic(vm->map, r, 4);
//	}
//
//	return (r);
//}




//void	op_ldi(t_vm *vm, t_proc *p)
//{
//	int arg;
//	int r[3];
//	int t;
//
//	arg = 0;
////	printf("SHIFT==%d\n", calc_shift(p, 10, 2));
//	r[0] = vm->map[(p->pc + calc_shift(p, 10, 2)) % MEM_SIZE];
//	t = (r[0] > 0 && r[0] <= REG_NUMBER);
////	print_map_fragment(vm->map, p->pc, p->pc + 7);
//	if (check_ldi_args(p) && t)
//	{
//		r[1] = get_ldi_arg_1(vm, p);
//		r[2] = get_ldi_arg_2(vm, p);
//		if (p->arg[0] == 3)
//		{
////			r[1] = get_magic(vm->map, r[1], 2);
//			arg = (short)((r[1] + r[2]) % IDX_MOD);
//		}
//
//		else
//			arg = (r[1] + r[2]) % MEM_SIZE;
//
////		arg = r[1] + r[2];
////		arg = arg % IDX_MOD;
//
//		printf("P    %d | ldi %d %d r%d\n", p->num, r[1], r[2], r[0]);
//		printf("        | -> load from %d + %d = %d ", r[1], r[2], arg);
//		printf("(with pc and mod %d)\n", p->pc + arg);
//		arg = p->pc + arg;
//		print_map_fragment(vm->map, arg, arg + 4);
//		p->reg[r[0]] = get_magic(vm->map, arg, 4);
//	}
//	p->pc = (p->pc + move_carret(p, p->cur_cmd)) % MEM_SIZE;
//}
