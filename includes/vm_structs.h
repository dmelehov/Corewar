/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:51:36 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/08 14:36:50 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCTS_H
# define VM_STRUCTS_H

# define FLAGS_INIT (t_flags){0,-1,-1,-1,0,0}

typedef struct		s_players
{
	t_header		*header;
	char			*name;
	char			*comment;
	int				num;
}					t_players;

typedef struct		s_flags
{
	int				a;
	int				d;
	int				s;
	int				v;
	int				b;
	int				n;
}					t_flags;

typedef	struct		s_vm
{
	unsigned char	*map;
	int				pl_q;
	t_flags			*flags;
	t_players		players[4];
}					t_vm;

#endif
