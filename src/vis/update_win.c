/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:01:06 by fmallaba          #+#    #+#             */
/*   Updated: 2018/03/02 17:34:53 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}

void		update_win(t_vm *vm, t_proc *p, int adr)
{
	attron(COLOR_PAIR(ft_abs(p->pl_num)));
	if ((vm->flags->n & 2) == 2)
	{
		mvprintw(adr % MEM_SIZE / 64 + 2, adr % MEM_SIZE % 64 * 3 + 3, "ff");
		mvprintw((adr + 1) % MEM_SIZE / 64 + 2, (adr + 1) % MEM_SIZE
			% 64 * 3 + 3, "ff");
		mvprintw((adr + 2) % MEM_SIZE / 64 + 2, (adr + 2) % MEM_SIZE
			% 64 * 3 + 3, "ff");
		mvprintw((adr + 3) % MEM_SIZE / 64 + 2, (adr + 3) % MEM_SIZE
			% 64 * 3 + 3, "ff");
	}
	else
	{
		mvprintw(adr % MEM_SIZE / 64 + 2, adr % MEM_SIZE % 64 * 3 + 3,
			"%02x", vm->map[adr % MEM_SIZE]);
		mvprintw((adr + 1) % MEM_SIZE / 64 + 2, (adr + 1) % MEM_SIZE
			% 64 * 3 + 3, "%02x", vm->map[(adr + 1) % MEM_SIZE]);
		mvprintw((adr + 2) % MEM_SIZE / 64 + 2, (adr + 2) % MEM_SIZE
			% 64 * 3 + 3, "%02x", vm->map[(adr + 2) % MEM_SIZE]);
		mvprintw((adr + 3) % MEM_SIZE / 64 + 2, (adr + 3) % MEM_SIZE
			% 64 * 3 + 3, "%02x", vm->map[(adr + 3) % MEM_SIZE]);
	}
}

static void	print_line(char *line, int *x, int *y)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i + 1] == '\0')
		{
			*x = 18;
			move(++(*y), *x);
			break ;
		}
		else if (line[i] != ' ')
			printw("%c", line[i]);
		move(*y, ++(*x));
	}
}

static void	print_game_over(void)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	if ((fd = open("media/game_over", O_RDONLY)))
		return ;
	y = 30;
	x = 18;
	move(y, x);
	attron(COLOR_PAIR(YELLOW_CLR));
	while (get_next_line(fd, &line) > 0)
	{
		print_line(line, &x, &y);
		ft_strdel(&line);
	}
	attron(COLOR_PAIR(DEF_CLR));
}

void		end_game(t_vm *vm)
{
	attron(COLOR_PAIR(DEF_CLR));
	attron(A_BOLD);
	mvprintw(7, 200, "Cycle : %d", vm->cycles);
	mvprintw(9, 200, "Processes : %-10d", vm->proc_alive);
	if (vm->winner)
	{
		mvprintw(42, 200, "The winner is : ");
		attron(COLOR_PAIR(ft_abs(vm->winner->num)));
		printw("%s", vm->winner->header->prog_name);
	}
	print_game_over();
	mvprintw(44, 200, "Press any key to finish");
	refresh();
	if ((vm->flags->n & 4) == 4)
		system("afplay -t 3.3 media/babah.mp3");
	while (getch() == ERR)
		;
	endwin();
}
