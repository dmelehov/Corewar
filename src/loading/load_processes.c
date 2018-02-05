/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:38:05 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 20:38:06 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					load_processes(t_core *core)
{
	t_player		*iter;
	unsigned int	size;

	size = get_players_size(core->players);
	core->players_lives = size;
	iter = core->players ? core->players : NULL;
	while (iter)
	{
		add_process(&core->process, ((MEM_SIZE) / size) * (iter->id - 1), 0);
		iter = iter->next;
	}
}
