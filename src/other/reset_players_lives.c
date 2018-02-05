/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_players_lives.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:08:04 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 16:08:06 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					reset_players_lives(t_player *players)
{
	t_player		*tmp;

	tmp = players ? players : NULL;
	while (tmp)
	{
		tmp->lives = 0;
		tmp = tmp->next;
	}
}
