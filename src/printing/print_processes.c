/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:23:35 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 17:23:39 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					print_processes(t_process *processes)
{
	t_process		*proc;
	int				i;

	i = 0;
	proc = processes ? processes : NULL;
	while (proc)
	{
		printf("------------------PROCESS %d------------------\n", ++i);
		printf("PC:\t\t%d\n", proc->pc);
		printf("REG:\t\t%d\n", proc->reg[0]);
		printf("ID:\t\t%d\n", proc->id);
		proc = proc->next;
	}
}
