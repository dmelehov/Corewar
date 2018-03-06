/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:05 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 18:59:20 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			init_proc(t_vm *vm, t_players *pl, int start)
{
	t_proc	*p;
	t_proc	*tmp;

	tmp = vm->proc;
	p = (t_proc *)ft_malloc_s(1, sizeof(t_proc));
	ft_bzero(p, sizeof(t_proc));
	vm->mpn += 1;
	p->num = vm->mpn;
	p->pc = start;
	p->reg[1] = pl->num;
	p->pl_num = pl->num;
	vm->proc_alive += 1;
	vm->proc = p;
	p->next = tmp;
}

/*
** Readind champion, validating its data;
** t_header struct declared in op.h
**
** .COR STRUCTURE
** 4	magic
** PROG_NAME_LENGTH
** '\0' + 3 bytes on NULL
** 4	size of executable code
** COMMENT_LENGTH
** '\0' + 3 bytes on NULL
** executable code
*/

t_header		*init_header_struct(unsigned char *data, int len)
{
	t_header	*hd;

	hd = (t_header *)ft_malloc_s(1, sizeof(t_header));
	hd->magic = get_magic(data, 0, 4);
	if (hd->magic != COREWAR_EXEC_MAGIC)
		M_ERROR(-1, "Nahuj takih chempionov bez magii");
	if (ft_strlen((char*)(data + 4)) > PROG_NAME_LENGTH)
		M_ERROR(-1, "Too big champion name.");
	ft_bzero(hd->prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(hd->prog_name, data + 4, PROG_NAME_LENGTH);
	hd->prog_size = get_magic(data, PROG_NAME_LENGTH + 8, 4);
	if (ft_strlen((char*)(data + PROG_NAME_LENGTH + 12)) > COMMENT_LENGTH)
		M_ERROR(-1, "Too big comment.");
	ft_bzero(hd->comment, PROG_NAME_LENGTH + 12);
	ft_memcpy(hd->comment, data + PROG_NAME_LENGTH + 12, COMMENT_LENGTH);
	if ((unsigned int)(len - HEADER) != hd->prog_size)
		M_ERROR(-1, "Prog size doesn't match real.");
	return (hd);
}

/*
** Operation table array
** Declared in op.h
** Describing comand attributes
*/

static void		init_op_tab(t_vm *vm)
{
	vm->op_tab[0] = (t_op){0, 0, {0}, 0, 0, 0, 0, 0};
	vm->op_tab[1] = (t_op){"live", 1, {T_DIR}, 1, 10, "", 0, 0};
	vm->op_tab[2] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "", 1, 0};
	vm->op_tab[3] = (t_op){"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "", 1, 0};
	vm->op_tab[4] = (t_op){"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "", 1, 0};
	vm->op_tab[5] = (t_op){"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "", 1, 0};
	vm->op_tab[6] = (t_op){"and", 3,
	{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, "", 1, 0};
	vm->op_tab[7] = (t_op){"or", 3,
	{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, "", 1, 0};
	vm->op_tab[8] = (t_op){"xor", 3,
	{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, "", 1, 0};
	vm->op_tab[9] = (t_op){"zjmp", 1, {T_DIR}, 9, 20, "", 0, 1};
	vm->op_tab[10] = (t_op){"ldi", 3,
	{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, "", 1, 1};
	vm->op_tab[11] = (t_op){"sti", 3,
	{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, "", 1, 1};
	vm->op_tab[12] = (t_op){"fork", 1, {T_DIR}, 12, 800, "", 0, 1};
	vm->op_tab[13] = (t_op){"lld", 2,
	{T_DIR | T_IND, T_REG}, 13, 10, "", 1, 0};
	vm->op_tab[14] = (t_op){"lldi", 3,
	{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, "", 1, 1};
	vm->op_tab[15] = (t_op){"lfork", 1, {T_DIR}, 15, 1000, "", 0, 1};
	vm->op_tab[16] = (t_op){"aff", 1, {T_REG}, 16, 2, "", 1, 0};
}

static void		init_funct_array(t_vm *vm)
{
	vm->op[0] = NULL;
	vm->op[1] = &op_live;
	vm->op[2] = &op_ld;
	vm->op[3] = &op_st;
	vm->op[4] = &op_add;
	vm->op[5] = &op_sub;
	vm->op[6] = &op_and;
	vm->op[7] = &op_or;
	vm->op[8] = &op_xor;
	vm->op[9] = &op_zjmp;
	vm->op[10] = &op_ldi;
	vm->op[11] = &op_sti;
	vm->op[12] = &op_fork;
	vm->op[13] = &op_lld;
	vm->op[14] = &op_lldi;
	vm->op[15] = &op_lfork;
	vm->op[16] = &op_aff;
}

t_vm			*init_vm_struct(int ac, char **av)
{
	t_vm	*vm;

	vm = (t_vm *)ft_malloc_s(1, sizeof(t_vm));
	vm->map = (unsigned char *)ft_strnew(MEM_SIZE);
	init_op_tab(vm);
	init_funct_array(vm);
	vm->proc = NULL;
	vm->proc_alive = 0;
	vm->cycles = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->check = CYCLE_TO_DIE;
	vm->live_amount = 0;
	vm->pl_q = get_players_quantity(ac, av);
	vm->mpn = 0;
	vm->flags = (t_flags *)ft_malloc_s(1, sizeof(t_flags));
	*(vm->flags) = FLAGS_INIT;
	vm->pls = NULL;
	vm->winner = NULL;
	vm->pr_info = 0;
	vm->info_pr = NULL;
	return (vm);
}
