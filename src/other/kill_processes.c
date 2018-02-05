/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:17:08 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/09 17:17:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				free_process(t_core *core, t_process *process)
{
	if (core->flags->v && core->flags->verbosity_eight)
	{
		ft_printf("Process %d has lived for", process->id);
		ft_printf(" %d cycles (CTD %d)\n", process->cycle, core->cycle_to_die);
	}
	free(process->reg);
	free(process->args);
	free(process);
}

void					kill_processes(t_core *core)
{
	t_process		*prew;
	t_process		*current;
	t_process		*next;

	prew = NULL;
	current = core->process ? core->process : NULL;
	next = core->process->next ? core->process->next : NULL;
	while (current)
	{
		if (!current->is_live)
		{
			free_process(core, current);
			if (prew)
				prew->next = next;
			else
				core->process = next;
		}
		else
		{
			current->is_live = 0;
			prew = current;
		}
		current = next;
		next = next ? next->next : NULL;
	}
}
