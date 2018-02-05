/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:41:23 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/23 16:41:25 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					add_player(t_player *players, t_header *header, unsigned int size, t_flags *flags)
{
	t_player		*player;
	t_player		*to_end;

	to_end = players;
	if (players->id == 0)
	{
		players->id = 1;
		players->number = flags->number ? flags->n : players->id;
		players->header = header;
		players->size = size;
	}
	else if ((player = (t_player *)malloc(sizeof(t_player))))
	{
		while (to_end->next)
			to_end = to_end->next;
		player->id = to_end->id + 1;
		player->number = flags->number ? flags->n : player->id;
		player->header = header;
		player->size = size;
		to_end->next = player;
		player->next = NULL;
	}
}
