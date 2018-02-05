/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:29:46 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:29:48 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						print_command_ld(t_core *core, t_process *process)
{
	if (core->flags->v && core->flags->verbosity_four)
	{
		printf("command: %s\t\t", g_op_tab[1].command);
		printf("pc: %x\t", core->map[process->pc]);
		printf("index: %d\t", process->pc);
		printf("cycle: %d\t", core->cycle);
		printf("process: %d\t\n", process->reg[0]);
	}
	return (0);
}

int						command_ld(t_core *core, t_process *process)
{
	t_player		*tmp;

	tmp = core->players ? core->players : NULL;
	print_command_ld(core, process);
	return (1);
}
