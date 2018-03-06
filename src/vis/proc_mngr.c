/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_mngr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:00:57 by fmallaba          #+#    #+#             */
/*   Updated: 2018/02/27 17:18:45 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			insert_color(int pc)
{
	int	color;

	attron(COLOR_PAIR(DEF_CLR));
	color = mvinch(pc / 64 + 2, pc % 64 * 3 + 3) & A_COLOR;
	if (color == COLOR_PAIR(PL_PR_CLR1))
		color = PL_CLR1;
	else if (color == COLOR_PAIR(PL_PR_CLR2))
		color = PL_CLR2;
	else if (color == COLOR_PAIR(PL_PR_CLR3))
		color = PL_CLR3;
	else if (color == COLOR_PAIR(PL_PR_CLR4))
		color = PL_CLR4;
	else if (color == COLOR_PAIR(PL_CLR1))
		color = PL_PR_CLR1;
	else if (color == COLOR_PAIR(PL_CLR2))
		color = PL_PR_CLR2;
	else if (color == COLOR_PAIR(PL_CLR3))
		color = PL_PR_CLR3;
	else if (color == COLOR_PAIR(PL_CLR4))
		color = PL_PR_CLR4;
	else if (color == COLOR_PAIR(DEF_PR_CLR))
		color = DEF_CLR;
	else if (color == COLOR_PAIR(DEF_CLR))
		color = DEF_PR_CLR;
	return (color);
}

void		add_proc(t_proc *p)
{
	int	color;

	color = insert_color(p->pc);
	(color < 6) ? color += 5 : color;
	attron(COLOR_PAIR(color));
	mvaddch(p->pc / 64 + 2, p->pc % 64 * 3 + 3,
		(char)mvinch(p->pc / 64 + 2, p->pc % 64 * 3 + 3));
	mvaddch(p->pc / 64 + 2, p->pc % 64 * 3 + 4,
		(char)mvinch(p->pc / 64 + 2, p->pc % 64 * 3 + 4));
}

void		del_proc(t_proc *p)
{
	int	color;

	color = insert_color(p->pc);
	(color > 5) ? color -= 5 : color;
	attron(COLOR_PAIR(color));
	mvaddch(p->pc / 64 + 2, p->pc % 64 * 3 + 3,
		(char)mvinch(p->pc / 64 + 2, p->pc % 64 * 3 + 3));
	mvaddch(p->pc / 64 + 2, p->pc % 64 * 3 + 4,
		(char)mvinch(p->pc / 64 + 2, p->pc % 64 * 3 + 4));
}

void		update_proc(t_vm *vm)
{
	t_proc	*p;

	p = vm->proc;
	while (p)
	{
		add_proc(p);
		p = p->next;
	}
}

void		kill_proc(t_vm *vm, int proc)
{
	attron(COLOR_PAIR(MSG_CLR));
	attron(A_BOLD | A_UNDERLINE);
	mvprintw(40, 200, "%d processes was killed on cycle %-5d",
		proc - vm->proc_alive, vm->cycles);
	attroff(A_BOLD | A_UNDERLINE);
	if (vm->proc_alive && (vm->flags->n & 4) == 4)
		system("afplay -t 1.5 media/ak-47.mp3");
}
