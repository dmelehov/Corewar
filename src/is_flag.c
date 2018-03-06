/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:35:44 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:34:14 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

bool	is_flag(char *av)
{
	char *flags;

	flags = "adsvbn";
	if (*av != '-' || ft_strlen(av) != 2)
		return (false);
	av++;
	while (*flags)
		if (*av == *flags++)
			return (true);
	return (false);
}

int		flag_attr(char **av, int i, int ac)
{
	if (av[i][1] == 'd' || av[i][1] == 's' || av[i][1] == 'v')
		return (1);
	if (av[i][1] == 'n')
	{
		if (i + 1 != ac && (ft_strequ(av[i + 1], "--stealth") ||
			ft_strequ(av[i + 1], "--sound")))
		{
			if (i + 2 != ac && (ft_strequ(av[i + 2], "--stealth") ||
				ft_strequ(av[i + 2], "--sound")))
				return (2);
			return (1);
		}
	}
	return (0);
}

void	if_jump_flag(t_vm *vm, int oldpc, int npc, int i)
{
	int	n;

	if (!vm->flags->n && vm->flags->v != -1 &&
		(vm->flags->v & 16) == 16 && i != 9)
	{
		n = (npc < oldpc) ? 4096 - oldpc + npc : npc - oldpc;
		if (n < 2)
			return ;
		ft_printf("ADV %d (%#06x -> %#06x) ", n, oldpc, oldpc + n);
		while (oldpc != npc)
		{
			ft_printf("%02x ", vm->map[oldpc]);
			oldpc++;
			oldpc = oldpc % MEM_SIZE;
		}
		ft_printf("\n");
	}
}
