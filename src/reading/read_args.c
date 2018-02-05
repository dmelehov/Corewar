/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:53:22 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/15 17:53:24 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						read_args(t_core *core, int ac, char **av)
{
	int					iter;
	int					players;

	iter = 0;
	players = 0;
	if (ac < 2)
		return (print_usage());
	while (++iter < ac)
	{
		players += read_flags(core, av, &iter);
		if (iter < ac)
			if (!validation(core, av[iter]))
				exit (0);
	}
	if (players > MAX_PLAYERS)
	{
		write (1, "Too many champions\n", 19);
		return (0);
	}
	ft_sort_list(core->players);
	return (1);
}
