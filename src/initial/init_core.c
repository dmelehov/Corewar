/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:25:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 20:25:58 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

t_core					*init_core(void)
{
	t_core				*core;

	if (!(core = (t_core *)malloc(sizeof(t_core))))
		return (NULL);
	core->map = init_map();
	core->cycle = 0;
	core->current_cycle = 0;
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = MAX_CHECKS;
	core->players_lives = 0;
	core->players = init_players();
	core->process = init_process();
	core->flags = init_flags();
	return (core);
}