/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:33:37 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 16:33:38 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						get_next_index(int command, int value)
{
	int			index;

	index = 0;
	index += g_sizes[command - 1][value >> 6];
	index += g_sizes[command - 1][value >> 4 & 3];
	index += g_sizes[command - 1][value >> 2 & 3];
	index += g_sizes[command - 1][value & 3];
	return (index);
}
