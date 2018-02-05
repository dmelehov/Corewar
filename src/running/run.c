/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:47:10 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 15:47:12 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					run(t_core *core)
{
	while (core->players_lives != 0)
	{
		core->players_lives = 0;
		FLAGS->dump && FLAGS->dump_cycle == CYCLE ? 0 : run_processes(core);
		reset_players_lives(core->players);
		kill_processes(core);
		if (core->players_lives >= NBR_LIVE || !core->max_checks)
		{
			core->max_checks = MAX_CHECKS;
			core->cycle_to_die -= CYCLE_DELTA;
			if (FLAGS->v && FLAGS->verbosity_two)
				printf("Cycle to die is now %d\n", core->cycle_to_die);
		}
		core->current_cycle = 1;
		core->max_checks--;
	}
	FLAGS->dump ? 0 : print_champ(core);
}
