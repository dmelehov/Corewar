/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:13:26 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 19:31:00 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Dependig from arg type
** function returns a value that command need
** for validation and execution
*/

int		get_arg_value(t_vm *vm, t_proc *p, int an)
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
		if (p->cur_cmd != 13)
			adr = p->pc + (p->arg_v[an] % IDX_MOD);
		else
			adr = p->pc + (p->arg_v[an] % MEM_SIZE);
		return (get_magic(vm->map, adr, 4));
	}
	return (p->arg[an]);
}

/*
** Calculate how many bytes we should skip
** depend an argument types and their
** relevantness
** to move process carret
*/

int		calc_shift(t_vm *vm, t_proc *p, int max_i)
{
	int res;
	int cmd;
	int i;

	res = 0;
	i = 0;
	cmd = p->cur_cmd;
	while (i < 3 && i < max_i)
	{
		if (p->arg[i] == 1)
			res += 1;
		else if (p->arg[i] == 2)
			res += (vm->op_tab[cmd].b2_dir == 0 ? 4 : 2);
		else if (p->arg[i] == 3)
			res += 2;
		i++;
	}
	res += vm->op_tab[cmd].arg_len + 1;
	return (res);
}

/*
** Reads data byte by byte and set it to int
** This function allows to avoid confusions
** with Little Endian machines
*/

int		get_magic(unsigned char *s, int start, int len)
{
	int magic;
	int i;

	i = 0;
	magic = 0;
	start = start % MEM_SIZE;
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

/*
** It takes a value from the registry with following value
** and write it to map
*/

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
	if (vm->flags->n)
		update_win(vm, p, adr);
}

/*
** Function encode data from a coding byte and read it to array
** This data set the type of arguments we should parse
*/

void	set_args_data(t_vm *vm, t_proc *p)
{
	int i;

	i = (p->pc + 1) % MEM_SIZE;
	p->arg[0] = (vm->map[i] & 0xc0) >> 6;
	p->arg[1] = (vm->map[i] & 0x30) >> 4;
	p->arg[2] = (vm->map[i] & 0x0c) >> 2;
}
