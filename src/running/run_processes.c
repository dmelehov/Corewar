/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:33:43 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 17:33:44 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					run_processes(t_core *core)
{
	t_process		*process;

	while (core->current_cycle < core->cycle_to_die)
	{
		if (FLAGS->v && FLAGS->verbosity_two)
			printf("It is now cycle %d\n", CYCLE);
		if (FLAGS->dump && CYCLE == FLAGS->dump_cycle)
		{
			print_map(core);
			break ;
		}
		process = core->process ? core->process : NULL;
		while (process)
		{
			process->cycle++;
			run_player(core, process);
			process = process->next;
		}
		CYCLE++;
		core->current_cycle++;
	}
}
