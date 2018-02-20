/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:28:46 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/16 07:37:51 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

#define START_POSITION (MEM_SIZE/vm->pl_q * (PL_NUM - p->num))

static void	check_champ_size(char *path, int len)
{
	if (len <=  0)
	{
		ft_printf("Error: File champs is too small to be a champion");
		M_ERROR(-1, "");
	}
	else if (len - HEADER > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s has too large a code (%d bytes > 682 bytes)", path, len);
		M_ERROR(-1, "");
	}
}

static t_proc	*init_proc(t_vm *vm, t_players *pl, int start)
{
	t_proc	*p;

	p = (t_proc *)ft_malloc_s(1, sizeof(t_proc));
	p->num = 1;
	p->pc = start;
	ft_bzero(p->reg, 68);
	p->reg[1] = pl->num;
	ft_bzero(p->arg, 12);
	ft_bzero(p->arg_v, 12);
	p->wait = 0;
	p->cur_cmd = 0;
	p->carry = 0;
	p->next = NULL;
	return (p);
}

void	read_champ_data(t_vm *vm, char *str, t_players *p)
{
	int	fd;
	int len;
	unsigned char	*s;

	if ((fd = open(str, O_RDONLY)) < 3)
		M_ERROR(-1, ft_strjoin("Can't read source file ", str));
	len = (int)lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	check_champ_size(str, len);
	s = (unsigned char *)ft_strnew(len);
	if (read(fd, s, len) <= 0)
		M_ERROR(-1, ft_strjoin("Can't read source file ", str));
	p->header = init_header_struct(s, len);
	p->proc = NULL;
	ft_memcpy(vm->map + START_POSITION, s + HEADER, len - HEADER);
	p->proc = init_proc(vm, p, START_POSITION);
}
