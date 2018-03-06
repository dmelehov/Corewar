/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:28:46 by dmelehov          #+#    #+#             */
/*   Updated: 2018/03/04 12:20:15 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

#define START_POSITION (MEM_SIZE/vm->pl_q * (PL_NUM - p->num))

static void		check_champ_size(char *path, int len)
{
	if (len <= 0)
	{
		ft_printf("Error: File champs is too small to be a champion");
		exit(-1);
	}
	else if (len - HEADER > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s has too large a code ", path);
		ft_printf("(%d bytes > 682 bytes)\n", len);
		exit(-1);
	}
}

static void		read_champ_data(t_vm *vm, char *str, t_players *p)
{
	int				fd;
	int				len;
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
	ft_memcpy(vm->map + START_POSITION, s + HEADER, len - HEADER);
	p->start = START_POSITION;
	p->len = len - HEADER;
	init_proc(vm, p, START_POSITION);
}

static void		get_champions(t_vm *vm, char *path, int num)
{
	t_players *p;
	t_players *tmp;

	tmp = vm->pls;
	p = (t_players *)ft_malloc_s(1, sizeof(t_players));
	*p = PLAYER_INIT;
	vm->pls = p;
	p->next = tmp;
	vm->winner = p;
	read_champ_data(vm, path, p);
}

int				get_players_quantity(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		if (ft_strequ(ft_strrchr(av[i], '.'), ".cor"))
			j++;
		i++;
	}
	if (j > 4)
		M_ERROR(-1, "Too many champions");
	else if (j == 0)
		print_usage();
	return (j);
}

void			check_arguments(t_vm *vm, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	parse_flags(vm, ac, av);
	while (i < ac)
	{
		if (is_flag(av[i]))
			i += flag_attr(av, i, ac);
		else if (ft_strequ(ft_strrchr(av[i], '.'), ".cor"))
			get_champions(vm, av[i], j++);
		else
			M_ERROR(-1, ft_strjoin("Invalid file name ", av[i]));
		i++;
	}
}
