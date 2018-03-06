/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:00:46 by fmallaba          #+#    #+#             */
/*   Updated: 2018/02/25 17:00:54 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		get_plr_arr(t_players *p[], t_players *pls)
{
	int	plr;

	plr = -1;
	while (pls)
	{
		p[++plr] = pls;
		pls = pls->next;
	}
}

static void	load_plr(t_vm *vm, t_players *p[], int *plr, int *i)
{
	int			cur;

	attron(COLOR_PAIR(ft_abs(p[*plr]->num)));
	cur = -1;
	while (++cur < p[*plr]->len)
	{
		if (*i && !(*i % 64))
			printw("\n  ");
		if ((vm->flags->n & 2) == 2)
			printw(" ff");
		else
			printw(" %02x", vm->map[*i]);
		*i += 1;
	}
	attron(COLOR_PAIR(DEF_CLR));
	*plr -= 1;
}

void		load_map(t_vm *vm)
{
	int			i;
	int			plr;
	t_players	*p[vm->pl_q];

	i = -1;
	get_plr_arr(p, vm->pls);
	move(2, 2);
	plr = vm->pl_q - 1;
	while (++i < 4096)
	{
		if (i == p[plr]->start)
			load_plr(vm, p, &plr, &i);
		if (i && !(i % 64))
			printw("\n  ");
		if ((vm->flags->n & 2) == 2)
			printw(" ff");
		else
			printw(" %02x", vm->map[i]);
	}
	printw("\n");
	update_proc(vm);
}
