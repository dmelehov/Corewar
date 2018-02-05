/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:58:46 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 17:58:47 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					add_process(t_process **processes, int start, int exec)
{
	t_process		*proc;

	if ((*processes)->pc == -1)
	{
		(*processes)->pc = 0;
		(*processes)->reg[0] = -1;
		(*processes)->player = -1;
		(*processes)->id = 1;
		(*processes)->cycles_to_exec = 0;
	}
	else
	{
		proc = init_process();
		proc->pc = start;
		proc->player = -(((*processes)->reg[0] * -1) + 1);
		proc->cycles_to_exec = exec;
		proc->reg[0] = -(((*processes)->reg[0] * -1) + 1);
		proc->id = (*processes)->id + 1;
		proc->next = (*processes);
		(*processes) = proc;
	}
}
