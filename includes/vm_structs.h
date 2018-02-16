/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:51:36 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/09 19:45:36 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCTS_H
# define VM_STRUCTS_H

# define PL_NUM 0xffffffff
# define PR_LIM 930
# define GAME_LIM 950
# define FLAGS_INIT (t_flags){0,-1,-1,-1,0,0}
#define HEADER (PROG_NAME_LENGTH + COMMENT_LENGTH + 16)

typedef struct		s_proc
{
	int				pc;
	int 			num;
	int 			reg[REG_NUMBER + 1];
	int 			arg[3];
	int 			cur_cmd;
	int 			wait;
	int 			carry;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_players
{
	int				num;
	int 			turn;
	int 			live;
	t_proc			*proc;
	t_header		*header;
	struct s_players	*next;
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
	void			(*op[17])(struct s_vm *vm, t_proc *p);
	int				pl_q;
	t_flags			*flags;
	t_players		*pls;
	int				cycles;
	int 			cycles_to_dye;
	int				no_one_alive;
}					t_vm;

/*
 * .COR STRUCTURE
 * 4	magic
 * PROG_NAME_LENGTH
 * '\0' + 3 bytes on NULL
 * 4	size of executable code
 * COMMENT_LENGTH
 * '\0' + 3 bytes on NULL
 * executable code
 */

#endif
