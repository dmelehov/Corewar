/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:57:21 by fmallaba          #+#    #+#             */
/*   Updated: 2018/02/27 17:38:25 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void	draw_frame(void)
{
	attron(COLOR_PAIR(FRAME_CLR));
	mvhline(0, 0, ' ', 253);
	mvhline(67, 0, ' ', 254);
	mvvline(0, 0, ' ', 67);
	mvvline(0, 197, ' ', 67);
	mvvline(0, 253, ' ', 67);
}

static void	init_colors(void)
{
	init_pair(PL_CLR1, COLOR_GREEN, COLOR_BLACK);
	init_pair(PL_CLR2, COLOR_BLUE, COLOR_BLACK);
	init_pair(PL_CLR3, COLOR_RED, COLOR_BLACK);
	init_pair(PL_CLR4, COLOR_CYAN, COLOR_BLACK);
	init_pair(PL_PR_CLR1, COLOR_BLACK, COLOR_GREEN);
	init_pair(PL_PR_CLR2, COLOR_BLACK, COLOR_BLUE);
	init_pair(PL_PR_CLR3, COLOR_BLACK, COLOR_RED);
	init_pair(PL_PR_CLR4, COLOR_BLACK, COLOR_CYAN);
	init_pair(FRAME_CLR, COLOR_WHITE, COLOR_WHITE);
	init_pair(DEF_CLR, COLOR_WHITE, COLOR_BLACK);
	init_pair(DEF_PR_CLR, COLOR_BLACK, COLOR_WHITE);
	init_pair(MSG_CLR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(YELLOW_CLR, COLOR_YELLOW, COLOR_BLACK);
}

void		init_scr(t_vm *vm)
{
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	mousemask(BUTTON1_CLICKED, NULL);
	curs_set(0);
	start_color();
	init_colors();
	noecho();
	load_map(vm);
	load_subwin(vm, 1, 50);
	draw_frame();
	refresh();
}
