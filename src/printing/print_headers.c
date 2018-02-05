/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_headers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:21:09 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 17:21:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					print_header(t_header *header, unsigned int size)
{
	if (header)
	{
		header->magic ? printf("MAGIC : %x\n\n", header->magic) : 0;
		header->prog_name ? print_prog_attr(header->prog_name, (PROG_NAME_LENGTH)) : 0;
		header->comment ? print_prog_attr(header->comment, (COMMENT_LENGTH)) : 0;
		header->prog ? print_prog_attr(header->prog, size - ((PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16)) : 0;
	}
}

void					print_headers(t_player *players)
{
	t_player			*t_player;

	t_player = players ? players : NULL;
	while (t_player)
	{
		printf("------------------PLAYER ID %d------------------\n", t_player->id);
		print_header(t_player->header, t_player->size);
		t_player = t_player->next;
		printf("-----------------------------------------------\n\n");
	}
}
