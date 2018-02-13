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
int			get_magic(unsigned char *s);

/*
** game_cycle.c
*/

void 		game_cycle(t_vm *vm);


#endif
