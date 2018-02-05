/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 22:28:39 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/28 22:28:40 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					load_players_on_the_map(t_core *core)
{
	t_player		*t_player;
	int				i;
	int				j;

	t_player = core->players ? core->players : NULL;
	while (t_player)
	{
		i = -1;
		j = ((MEM_SIZE) / get_players_size(core->players)) * (t_player->id - 1);
		if (core->map && t_player->header)
		{
			while (++i < (int)t_player->header->prog_size)
				core->map[j++] = t_player->header->prog[i];
		}
		t_player = t_player->next;
	}
}
