/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:51:36 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 19:07:23 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCTS_H
# define VM_STRUCTS_H

# define PL_NUM 0xffffffff
# define FLAGS_INIT (t_flags){0,-1,-1,-1,0,0}
# define PLAYER_INIT (t_players){PL_NUM - num, 0, 0, 0, NULL, 0, 0, NULL}
# define HEADER (PROG_NAME_LENGTH + COMMENT_LENGTH + 16)

/*
** colors define
*/

# define PL_CLR1 1
# define PL_CLR2 2
# define PL_CLR3 3
# define PL_CLR4 4
# define DEF_CLR 5
# define PL_PR_CLR1 6
# define PL_PR_CLR2 7
# define PL_PR_CLR3 8
# define PL_PR_CLR4 9
# define DEF_PR_CLR 10
# define FRAME_CLR 11
# define MSG_CLR 12
# define YELLOW_CLR 13

typedef struct			s_proc
{
	int					pc;
	int					num;
	int					reg[REG_NUMBER + 1];
	int					arg[3];
	int					arg_v[3];
	int					cur_cmd;
	int					wait;
	int					carry;
	int					is_alive;
	int					age;
	int					pl_num;
	struct s_proc		*next;
}						t_proc;

typedef struct			s_players
{
	int					num;
	int					turn;
	int					live;
	int					llc;
	t_header			*header;
	int					start;
	int					len;
	struct s_players	*next;
}						t_players;

typedef struct			s_flags
{
	int					a;
	int					d;
	int					s;
	int					v;
	int					b;
	int					n;
}						t_flags;

typedef	struct			s_vm
{
	unsigned char		*map;
	t_op				op_tab[17];
	void				(*op[17])(struct s_vm *vm, t_proc *p);
	t_proc				*proc;
	int					proc_alive;
	int					cycles;
	int					cycles_to_die;
	int					check;
	int					live_amount;
	int					pl_q;
	int					mpn;
	t_flags				*flags;
	t_players			*pls;
	t_players			*winner;
	int					pr_info;
	t_proc				*info_pr;
}						t_vm;

/*
** .COR STRUCTURE
** 4	magic
** PROG_NAME_LENGTH
** '\0' + 3 bytes on NULL
** 4	size of executable code
** COMMENT_LENGTH
** '\0' + 3 bytes on NULL
** executable code
*/

#endif
