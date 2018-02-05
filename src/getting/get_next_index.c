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

int						get_next_index(t_process *process, unsigned char *map,
										int command, int value)
{
	int			index;
	int			step;
	int			i;

	i = -1;
	index = 0;
	step = 0;
	ft_bzero(process->args, MAX_ARGS_NUMBER);
	while (++i < g_op_tab[command - 1].count_args && i < MAX_ARGS_NUMBER) {
		step = g_sizes[command - 1][value >> (6 - i * 2) & 3];
		process->args[i].type = value >> (6 - i * 2) & 3;
		process->args[i].arg = get_value_from_map(map, process->pc + 1 +
			g_op_tab[command - 1].codage_octal + index, step);
		index += step;
	}
	return (index);
}
