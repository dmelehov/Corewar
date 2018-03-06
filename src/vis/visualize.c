/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:01:13 by fmallaba          #+#    #+#             */
/*   Updated: 2018/03/06 17:54:01 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	kbhit(int stop)
{
	int	ch;

	ch = getch();
	if (ch == ERR)
		return (stop);
	if (ch == 32)
		return ((!stop) ? 1 : 0);
	else
		ungetch(ch);
	return (stop);
}

static int	check_ch(int ch, int *stop, int *sleep)
{
	if (ch == ERR)
		return (0);
	if (ch == 32)
	{
		*stop = 0;
		return (1);
	}
	else if (ch == 114 && *sleep < 991)
		*sleep += 10;
	else if (ch == 101 && *sleep < 1000)
		*sleep += 1;
	else if (ch == 113 && *sleep > 10)
		*sleep -= 10;
	else if (ch == 119 && *sleep > 1)
		*sleep -= 1;
	return (0);
}

static void	draw_pr_frame(void)
{
	attron(COLOR_PAIR(YELLOW_CLR));
	mvprintw(45, 200, "+");
	mvprintw(45, 249, "+");
	mvprintw(66, 200, "+");
	mvprintw(66, 249, "+");
	mvhline(45, 201, '-', 48);
	mvhline(66, 201, '-', 48);
	mvvline(46, 200, '|', 20);
	mvvline(46, 249, '|', 20);
	mvvline(46, 222, '|', 20);
}

static void	check_mevent(t_vm *vm)
{
	MEVENT	event;
	t_proc	*proc;

	if (getmouse(&event) == OK && (event.bstate & BUTTON1_CLICKED))
	{
		proc = vm->proc;
		while (proc)
		{
			if (proc->pc / 64 + 2 == event.y &&
				(proc->pc % 64 * 3 + 3 == event.x ||
				proc->pc % 64 * 3 + 4 == event.x))
			{
				draw_pr_frame();
				draw_pr_block(proc);
				vm->pr_info = 1;
				vm->info_pr = proc;
				return ;
			}
			proc = proc->next;
		}
	}
}

void		visualize(t_vm *vm)
{
	static int	stop = 1;
	static int	sleep = 50;
	int			ch;

	if (!vm->cycles)
		init_scr(vm);
	usleep(1000000 / (unsigned int)sleep);
	stop = kbhit(stop);
	update_proc(vm);
	if (stop)
		while ((ch = getch()) != 115)
		{
			if (ch == KEY_MOUSE)
				check_mevent(vm);
			else if (check_ch(ch, &stop, &sleep))
				break ;
			load_subwin(vm, stop, sleep);
		}
	else
	{
		check_ch(getch(), &stop, &sleep);
		load_subwin(vm, stop, sleep);
	}
	refresh();
}
