/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:22:50 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/18 16:22:51 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					swap_list(t_player *p1, t_player *p2)
{
	int				num;
	unsigned int	size;
	t_header		*header;

	num = 0;
	size = 0;
	header = NULL;
	num = p1->number;
	size = p1->size;
	header = p1->header;
	p1->number = p2->number;
	p1->size = p2->size;
	p1->header = p2->header;
	p2->number = num;
	p2->size = size;
	p2->header = header;
}

void					ft_sort_list(t_player *players)
{
	t_player		*tmp1;
	t_player		*tmp2;

	tmp1 = players;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->number > tmp2->number)
				swap_list(tmp1, tmp2);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
