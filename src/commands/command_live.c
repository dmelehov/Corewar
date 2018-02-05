/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:16:16 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/16 18:16:17 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

// static void				print_command_live(t_core *core, t_process *process)
// {
// 	if (core->flags->v && core->flags->verbosity_four)
// 	{
// 		printf("command: %s\t\t", g_op_tab[0].command);
// 		printf("pc: %x\t", core->map[process->pc]);
// 		printf("index: %d\t", process->pc);
// 		printf("cycle: %d\t", core->cycle);
// 		printf("process: %d\t\n", process->reg[0]);
// 	}
// }

static void				print_flag_v(t_core *core, t_player *player,
										t_process *process)
{
	if (core->flags->v && core->flags->verbosity_one)
		printf("Player %d (%s) is said to be alive\n",
				player->number, player->header->prog_name);
	if (core->flags->v && core->flags->verbosity_four)
		printf("P%5d | %s %d\n", process->id, "live", player->id * -1);
}

int						command_live(t_core *core, t_process *process)
{
	t_player		*tmp;

	tmp = core->players ? core->players : NULL;
	// print_command_live(core, process);
	process->is_live = 1;
	core->players_lives++;
	while (tmp)
	{
		if (process->player * -1 == tmp->number)
		{
			tmp->lives++;
			print_flag_v(core, tmp, process);
			core->champ = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	return (1);
}
