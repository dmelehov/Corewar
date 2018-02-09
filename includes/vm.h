/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:00:09 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/09 14:20:00 by dmelehov         ###   ########.fr       */
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

/*
** parse_flags.c
*/

void	parse_flags(t_vm *vm, int ac, char **av);

/*
** parse_player_data.c
*/

void	get_champions_data(t_vm *vm, char *str, int count);

#endif
