/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_a_d_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:01:56 by fmallaba          #+#    #+#             */
/*   Updated: 2018/02/25 17:01:58 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	check_a_flag(t_vm *vm, int ac, char **av)
{
	int	i;

	i = -1;
	while (++i < ac)
		if (ft_strequ(av[i], "-a"))
			vm->flags->a = 1;
}

void	check_d_flag(t_vm *vm, int ac, char **av)
{
	int	i;

	i = -1;
	while (++i < ac)
		if (ft_strequ(av[i], "-d"))
		{
			if (i + 1 == ac)
				M_ERROR(-1, "Can't read source file -d");
			vm->flags->d = ft_atoi(av[++i]);
		}
}
