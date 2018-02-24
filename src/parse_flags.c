/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:35:44 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:33:53 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	check_a_flag(t_vm *vm, int ac, char **av)
{
	int 	i;

	i = -1;
	while (++i < ac)
		if (ft_strequ(av[i], "-a"))
			vm->flags->a = 1;
}

static void	check_d_flag(t_vm *vm, int ac, char **av)
{
	int 	i;

	i = -1;
	while (++i < ac)
		if (ft_strequ(av[i], "-d"))
		{
			if (i + 1 == ac)
				M_ERROR(-1, "Can't read source file -d");
			vm->flags->d = ft_atoi(av[++i]);
		}
}

static void	check_s_flag(t_vm *vm, int ac, char **av)
{
	int 	i;

	i = -1;
	while (++i < ac)
		if (ft_strequ(av[i], "-s"))
		{
			if (i + 1 == ac)
				M_ERROR(-1, "Can't read source file -s");
			vm->flags->s = ft_atoi(av[++i]);
		}
}

static void	check_v_flag(t_vm *vm, int ac, char **av)
{
	int 	i;

	i = -1;
	while (++i < ac)
		if (ft_strequ(av[i], "-v"))
		{
			if (i + 1 == ac)
				M_ERROR(-1, "Can't read source file -v");
			vm->flags->v = ft_atoi(av[++i]);
		}
}

static void	check_b_flag(t_vm *vm, int ac, char **av)
{
	int 	i;

	i = -1;
	while (++i < ac)
		if (ft_strequ(av[i], "-b"))
			vm->flags->b = 1;
}

static void	check_n_flag(t_vm *vm, int ac, char **av)
{
	int 	i;

	i = -1;
	while (++i < ac)
		if (ft_strequ(av[i], "-n"))
			vm->flags->n = 1;
}

void	parse_flags(t_vm *vm, int ac, char **av)
{
	check_a_flag(vm, ac, av);
	check_d_flag(vm, ac, av);
	check_s_flag(vm, ac, av);
	check_v_flag(vm, ac, av);
	check_b_flag(vm, ac, av);
	check_n_flag(vm, ac, av);
}

