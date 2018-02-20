/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:00:09 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/07 17:50:31 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/includes/libft.h"
# include "vm_structs.h"

/*
** usage.c
*/

void	print_usage(void);

/*
** debug_printer.c
*/

void	print_flags_struct(t_flags *fl);
void	print_map_fragment(unsigned char *map, int start, int end);
void	print_map(unsigned char *map);
void	print_proc_struct(t_proc *proc);
void	print_header_struct(t_header *h);
void	print_player_struct(t_players *p);
void	print_registry(int *reg);
void	print_arguments(int *arg);

/*
** parse_flags.c
*/
void	parse_flags(t_vm *vm, int ac, char **av);

/*
** is_flag.c
*/

bool	is_flag(char *av);
int 	flag_attr(char *av);

/*
** parse_player_data.c
*/

void	get_champions_data(t_vm *vm, char *str, int count);
void	read_champ_data(t_vm *vm, char *str, t_players *p);

/*
** init_header.c
*/

t_header	*init_header_struct(unsigned char *data, int len);
int			get_magic(unsigned char *s,int start, int len);
int 		get_arg_value(t_vm *vm, t_proc *p, int an);

/*
** game_cycle.c
*/

void 		game_cycle(t_vm *vm);

/*
** operations.c
*/

void	update_map(t_vm *vm, t_proc *p, int r, int adr);
int		move_carret(t_proc *p, int cmd);
int		get_ind_value(t_vm *vm, t_proc *p, int pos);
int		calc_shift(t_proc *p, int cmd, int max_i);


void	op_live(t_vm *vm, t_proc *p);
void	op_ld(t_vm *vm, t_proc *p);
void	op_st(t_vm *vm, t_proc *p);
void	op_add(t_vm *vm, t_proc *p);
void	op_sub(t_vm *vm, t_proc *p);
void	op_and(t_vm *vm, t_proc *p);
void	op_or(t_vm *vm, t_proc *p);
void	op_xor(t_vm *vm, t_proc *p);
void	op_zjmp(t_vm *vm, t_proc *p);
void	op_ldi(t_vm *vm, t_proc *p);
void	op_sti(t_vm *vm, t_proc *p);
void	op_fork(t_vm *vm, t_proc *p);
void	op_lld(t_vm *vm, t_proc *p);
void	op_lldi(t_vm *vm, t_proc *p);
void	op_lfork(t_vm *vm, t_proc *p);
void	op_aff(t_vm *vm, t_proc *p);

/*
** argument_manager.c
*/

int		arg_checker(t_vm *vm, t_proc *p);


void		set_args_data(t_vm *vm, t_proc *p);




#endif
