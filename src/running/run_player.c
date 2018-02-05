/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:41:17 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 19:41:18 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					run_player(t_core *core, t_process *process)
{
	int			cmd;
	int			codage;
	int			octal;
	int			pc;

	pc = process->pc;
	cmd = get_value_from_map(core->map, process->pc, 1);
	codage = get_value_from_map(core->map, process->pc + 1, 1);
	octal = g_op_tab[cmd - 1].codage_octal;
	if (cmd != 0 && cmd < 17)
	{
		if (process->cycles_to_exec == g_op_tab[cmd - 1].cycles)
		{
			process->cycles_to_exec = 1;
			pc += g_op_tab[cmd - 1].codage_octal ?
			(octal + get_next_index(process, core->map, cmd, codage)) :
			(octal + g_sizes[cmd - 1][2]);
			pc++;
			get_command_from_array(core, process, cmd);
			process->pc = pc;
		}
		else
			process->cycles_to_exec++;
	}
}
