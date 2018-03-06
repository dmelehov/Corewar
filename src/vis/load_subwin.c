/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_subwin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:16:24 by fmallaba          #+#    #+#             */
/*   Updated: 2018/03/02 17:13:12 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		draw_pr_block(t_proc *proc)
{
	int		pos;

	attron(COLOR_PAIR(YELLOW_CLR));
	pos = 45;
	while (++pos < 66)
		mvhline(pos, 202, ' ', 47);
	if (!proc)
	{
		mvprintw(55, 210, "The process is killed :-(");
		return ;
	}
	mvvline(46, 222, '|', 20);
	pos = 45;
	mvprintw(++pos, 202, "Proc num : %-6d", proc->num);
	mvprintw(++pos, 202, "Proc player : %-6d", proc->pl_num);
	mvprintw(++pos, 202, "Proc pc : %-6d", proc->pc);
	mvprintw(++pos, 202, "Proc carry : %-6d", proc->carry);
	mvprintw(++pos, 202, "Proc alive : %-6d", proc->is_alive);
	pos = 45;
	while (++pos < 62)
		mvprintw(pos, 224, "Reg %d : %-10d", pos - 45, proc->reg[pos - 45]);
	attron(COLOR_PAIR(DEF_CLR));
}

static void	load_plr_data(t_vm *vm, int *pos)
{
	t_players	*p[vm->pl_q];
	int			plr;

	get_plr_arr(p, vm->pls);
	plr = vm->pl_q;
	while (plr--)
	{
		mvprintw(*pos, 200, "Player %d : ", p[plr]->num);
		attron(COLOR_PAIR(ft_abs(p[plr]->num)));
		printw("%s", p[plr]->header->prog_name);
		attron(COLOR_PAIR(DEF_CLR));
		mvprintw(*pos + 1, 202, "Last live :%21d", p[plr]->llc);
		mvprintw(*pos + 2, 202, "Lives in current period :%7d", p[plr]->live);
		*pos += 4;
	}
}

static int	load_scale_help(t_players *p, float lives[], int *i)
{
	int	sum;

	sum = 0;
	while (p)
	{
		*i += 1;
		lives[*i] = p->live;
		sum += p->live;
		p = p->next;
	}
	return (sum);
}

void		load_scale(t_vm *vm)
{
	float		lives[4];
	int			i;
	float		sum;
	int			count[2];

	i = -1;
	sum = load_scale_help(vm->pls, lives, &i);
	count[0] = -1;
	while (i >= 0 && sum > 0)
	{
		count[1] = -1;
		while (++(count[1]) < (int)(lives[i] / sum * 50))
		{
			attron(COLOR_PAIR(vm->pl_q - i));
			printw("-");
			count[0] += 1;
		}
		i--;
	}
	if (count[0] == -1)
		attron(COLOR_PAIR(DEF_CLR));
	while (++(count[0]) < 50)
		printw("-");
	attron(COLOR_PAIR(DEF_CLR));
}

void		load_subwin(t_vm *vm, int stop, int sleep)
{
	int			pos;

	attron(COLOR_PAIR(DEF_CLR));
	attron(A_BOLD);
	if (stop)
		mvprintw(2, 200, "** PAUSED **  ");
	else
		mvprintw(2, 200, "** RUNNING **");
	mvprintw(4, 200, "Cycles/second limit : %-4d", sleep);
	mvprintw(7, 200, "Cycle : %d", vm->cycles);
	mvprintw(9, 200, "Processes : %-10d", vm->proc_alive);
	pos = 11;
	load_plr_data(vm, &pos);
	mvprintw((pos += 2), 200, "Live breakdown for current period :");
	mvprintw((pos += 1), 200, "[");
	load_scale(vm);
	printw("]");
	mvprintw((pos += 2), 200, "CYCLE_TO_DIE : %-5d", vm->cycles_to_die);
	mvprintw((pos += 2), 200, "CYCLE_DELTA : %d", 50);
	mvprintw((pos += 2), 200, "NBR_LIVE : %d", 21);
	mvprintw((pos += 2), 200, "MAX_CHECKS : %d", 10);
	attroff(A_BOLD);
	if (vm->pr_info)
		draw_pr_block(vm->info_pr);
}
