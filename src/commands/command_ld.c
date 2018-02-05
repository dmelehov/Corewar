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

static void				print_flag_v(t_core *core, t_process *process)
{
	if (core->flags->v && core->flags->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "ld");
		printf("%d r%d\n", process->args[0].arg, process->args[1].arg);
	}
}

int						command_ld(t_core *core, t_process *process)
{
	if (ARGS[0].type == DIR_CODE)
	{
		if (ARGS[1].arg <= REG_NUMBER)
			REG[ARGS[1].arg - 1] = ARGS[0].arg;
	}
	else if (ARGS[0].type == IND_CODE)
	{
		if (ARGS[1].arg <= REG_NUMBER)
			REG[ARGS[1].arg - 1] = get_value_from_map(MAP, ARGS[0].arg % MEM_SIZE, 4);
	}
	print_flag_v(core, process);
	return (1);
}
