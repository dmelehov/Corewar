/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:00:09 by dmelehov          #+#    #+#             */
/*   Updated: 2018/03/02 17:34:51 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/includes/libft.h"
# include "vm_structs.h"
# include <ncurses.h>

/*
** usage.c
*/

void		print_usage(void);

/*
** initializations.c
*/

t_vm		*init_vm_struct(int ac, char **av);
void		init_proc(t_vm *vm, t_players *pl, int start);
t_header	*init_header_struct(unsigned char *data, int len);

/*
** parse_player_data.c
*/

void		check_arguments(t_vm *vm, int ac, char **av);
int			get_players_quantity(int ac, char **av);

/*
** service.c
*/

void		set_args_data(t_vm *vm, t_proc *p);
void		update_map(t_vm *vm, t_proc *p, int r, int adr);
int			get_magic(unsigned char *s, int start, int len);
int			calc_shift(t_vm *vm, t_proc *p, int max_i);
int			get_arg_value(t_vm *vm, t_proc *p, int an);

/*
** game_process_revision.c
*/

void		live_manager(t_vm *vm, t_players *pl);
void		check_cycles_to_die(t_vm *vm, int *cnt);

/*
** game_cycle.c
*/

void		game_cycle(t_vm *vm);

/*
** argument_manager.c
*/

int			arg_checker(t_vm *vm, t_proc *p);

/*
** all opperations are located in apropriated files
*/

void		op_live(t_vm *vm, t_proc *p);
void		op_ld(t_vm *vm, t_proc *p);
void		op_st(t_vm *vm, t_proc *p);
void		op_add(t_vm *vm, t_proc *p);
void		op_sub(t_vm *vm, t_proc *p);
void		op_and(t_vm *vm, t_proc *p);
void		op_or(t_vm *vm, t_proc *p);
void		op_xor(t_vm *vm, t_proc *p);
void		op_zjmp(t_vm *vm, t_proc *p);
void		op_ldi(t_vm *vm, t_proc *p);
void		op_sti(t_vm *vm, t_proc *p);
void		op_fork(t_vm *vm, t_proc *p);
void		op_lld(t_vm *vm, t_proc *p);
void		op_lldi(t_vm *vm, t_proc *p);
void		op_lfork(t_vm *vm, t_proc *p);
void		op_aff(t_vm *vm, t_proc *p);

/*
** parse_flags.c
*/

void		parse_flags(t_vm *vm, int ac, char **av);

/*
** check_a_d_flags.c
*/

void		check_a_flag(t_vm *vm, int ac, char **av);
void		check_d_flag(t_vm *vm, int ac, char **av);

/*
** is_flag.c
*/

bool		is_flag(char *av);
int			flag_attr(char **av, int i, int ac);
void		if_jump_flag(t_vm *vm, int oldpc, int npc, int i);

/*
** prints.c
*/

void		print_intro(t_vm *vm);
void		print_map(unsigned char *map);
void		print_winner(t_vm *vm);

/*
** visualize.c
*/

void		visualize(t_vm *vm);

/*
** update_win.c
*/

void		update_win(t_vm *vm, t_proc *p, int adr);
void		end_game(t_vm *vm);

/*
** proc_mngr.c
*/

int			insert_color(int pc);
void		add_proc(t_proc *p);
void		del_proc(t_proc *p);
void		update_proc(t_vm *vm);
void		kill_proc(t_vm *vm, int proc);

/*
** load_map.c
*/

void		load_map(t_vm *vm);
void		get_plr_arr(t_players *p[], t_players *pls);

/*
** load_subwin.c
*/

void		load_subwin(t_vm *vm, int stop, int sleep);
void		draw_pr_block(t_proc *proc);

/*
** init_scr.c
*/

void		init_scr(t_vm *vm);

#endif
