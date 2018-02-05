/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:46:16 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 20:46:17 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

t_player				*init_players(void)
{
	t_player			*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->id = 0;
	player->number = 0;
	player->size = 0;
	player->lives = 0;
	player->header = NULL;
	player->next = NULL;
	return (player);
}
