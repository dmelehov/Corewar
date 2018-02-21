/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:02:30 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/12 16:54:09 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		swap_players(t_players *p)
{
	t_players	*tmp;
	t_players	*tmp2;

	tmp = p;
	tmp2 = p->next;
	if (p->next->next)
		swap_players(p->next);
	tmp2->next = tmp;
	tmp->next = NULL;
}

t_players	*sort_players(t_players *p)
{
	t_players *tmp;
	int j;

	tmp = p;
	j = -1;
	while (tmp->next)
		tmp = tmp->next;
	swap_players(p);
	return (tmp);
}

void	get_champions(t_vm *vm, char *path, int num)
{
	t_players *p;
	t_players *tmp;

	tmp = vm->pls;
	p = (t_players *)ft_malloc_s(1, sizeof(t_players));
	*p = (t_players){PL_NUM - num, 0, 0, 0, 0, NULL, NULL, NULL};
	if (!tmp)
	{
		vm->pls = p;
		tmp = p;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = p;
		tmp = tmp->next;
	}
	read_champ_data(vm, path, tmp);
}

void	check_arguments(t_vm *vm, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	parse_flags(vm, ac, av);
	while (i < ac)
	{
		if (is_flag(av[i]))
			i += flag_attr(av[i]);
		else if (ft_strequ(ft_strrchr(av[i], '.'), ".cor"))
			get_champions(vm, av[i], j++);
		i++;
	}
	if (vm->pl_q > 1)
		vm->pls = sort_players(vm->pls);
}

int		get_players_quantity(int ac, char **av)
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

t_flags	*init_flags_struct(void)
{
	t_flags	*flags;

	flags = (t_flags *)ft_malloc_s(1, sizeof(t_flags));
	*flags = FLAGS_INIT;
	return (flags);
}

void	init_funct_array(t_vm *vm)
{
	vm->op[0] = NULL;
	vm->op[1] = &op_live;
	vm->op[2] = &op_ld;
	vm->op[3] = &op_st;
	vm->op[4] = &op_add;
	vm->op[5] = &op_sub;
	vm->op[6] = &op_and;
	vm->op[7] = &op_or;
	vm->op[8] = &op_xor;
	vm->op[9] = &op_zjmp;
	vm->op[10] = &op_ldi;
	vm->op[11] = &op_sti;
	vm->op[12] = &op_fork;
	vm->op[13] = &op_lld;
	vm->op[14] = &op_lldi;
	vm->op[15] = &op_lfork;
	vm->op[16] = &op_aff;
}

t_vm	*init_vm_struct(int ac, char **av)
{
	t_vm	*vm;

	vm = (t_vm *)ft_malloc_s(1, sizeof(t_vm));
	vm->map = (unsigned char *)ft_strnew(MEM_SIZE);
	vm->pl_q = get_players_quantity(ac, av);
	vm->flags = init_flags_struct();
	vm->pls = NULL;
	vm->cycles_to_dye = CYCLE_TO_DIE;
	vm->cycles = 0;
	vm->proc_alive = 0;
	vm->live_amount = 0;
	vm->check = CYCLE_TO_DIE;
	vm->winner = NULL;
	init_funct_array(vm);
	return (vm);
}

void	print_winner(t_players *pl)
{
	printf("Contestant %d, \"%s\", has won !\n",
		   (PL_NUM - pl->num + 1), pl->header->prog_name);
}

void	printer_nah(t_vm *vm)
{
	t_players	*pl;
	t_proc		*pr;

	pl = vm->pls;
	while (pl)
	{
		ft_printf("{red|b}Player with name {%s}{eoc}\n", pl->header->prog_name);
		ft_printf("--------------------\n\n");
		pr = pl->proc;
		while (pr)
		{
			print_proc_struct(pr);
			print_map_fragment(vm->map, pr->pc, pr->pc + 5);

			pr = pr->next;
		}
		pl = pl->next;
//		ft_printf("--------------------\n\n");
	}
}

int		main(int ac, char **av)
{
	t_vm	*vm;

	if (ac < 2)
		print_usage();
	av++;
	ac--;
	vm = init_vm_struct(ac, av);
	check_arguments(vm, ac, av);
	game_cycle(vm);
	print_winner(vm->winner);
//	print_player_struct(vm->pls);
//	printer_nah(vm);
	return (0);
}
