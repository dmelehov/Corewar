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

	cmd = get_value_from_map(core->map, process->pc, 1);
	codage = get_value_from_map(core->map, process->pc + 1, 1);
	if (cmd != 0 && cmd < 17)
	{
		if (process->cycles_to_exec == g_op_tab[cmd - 1].cycles)
		{
			get_command_from_array(core, process, cmd);
			process->pc += g_op_tab[cmd - 1].codage_octal ?
			(2 + get_next_index(cmd, codage)) : (1 + g_sizes[cmd - 1][2]);
			process->cycles_to_exec = 1;
		}
		else
			process->cycles_to_exec++;
	}
}
