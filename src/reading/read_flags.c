/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 20:09:24 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/16 20:09:25 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static int				check_flag_d(t_core *core, char **av, int *i)
{
	if (ft_strcmp(av[(*i)], "-d") == 0 && av[(*i) + 1])
	{
		FLAGS->dump = 1;
		FLAGS->dump_cycle = ft_atoi(av[++(*i)]);
		++(*i);
		return (1);
	}
	return (0);
}

static int				check_flag_v(t_core *core, char **av, int *i)
{
	if (ft_strcmp(av[(*i)], "-v") == 0 && av[(*i) + 1])
	{
		FLAGS->v = 1;
		FLAGS->verbosity = ft_atoi(av[++(*i)]);
		++(*i);
		return (1);
	}
	return (0);
}

static int				check_flag_n(t_core *core, char **av, int *i)
{
	if (ft_strcmp(av[(*i)], "-n") == 0 && av[(*i) + 1])
	{
		FLAGS->number = 1;
		FLAGS->n = ft_atoi(av[++(*i)]);
		++(*i);
		return (1);
	}
	return (0);
}

static int				check_flags_clr(t_core *core, char **av, int *i)
{
	if (ft_strcmp(av[(*i)], "--color") == 0)
	{
		FLAGS->color = 1;
		++(*i);
		return (1);
	}
	return (0);	
}

int						read_flags(t_core *core, char **av, int *i)
{
	int			ret;

	ret = 0;
	FLAGS->number = 0;
	FLAGS->n = 0;
	while (av[(*i)])
	{
		if (!check_flag_d(core, av, i) && !check_flag_n(core, av, i) && \
			!check_flags_clr(core, av, i) && !check_flag_v(core, av, i))
		{
			ret = 1;
			break ;
		}
	}
	if (FLAGS->verbosity)
		read_verbosity(core);
	return (ret);
}
