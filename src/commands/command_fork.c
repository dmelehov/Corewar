/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:35:26 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:35:29 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						command_fork(t_core *core, t_process *process)
{
	if (core->flags->v && core->flags->verbosity_four)
	{
		printf("command: %s\t\t", g_op_tab[11].command);
		printf("pc: %x\t", core->map[process->pc]);
		printf("index: %d\t", process->pc);
		printf("cycle: %d\t", core->cycle);
		printf("reg[0]: %d\t\n", process->reg[0]);
	}
	return (0);
}
