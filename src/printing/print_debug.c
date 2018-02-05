/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:44:11 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/22 20:44:14 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/vm.h"

// void					print_debug(t_core *core)
// {
// 	int				i;
// 	int				cmd;
	
// 	i = 0;
// 	cmd = 0;
// 	while (i + 1 < MEM_SIZE)
// 	{
// 		cmd = get_value_from_map(core->map, i, 1);
// 		if (cmd != 0 && cmd <= 17 && g_op_tab[cmd - 1].codage_octal)
// 		{
// 			printf("command : %s\t\tpc : %x\tindex : %d\tnext index = %d\n", g_op_tab[cmd - 1].command, core->map[i], i,
// 				get_next_index(get_value_from_map(core->map, i, 1) - 1, get_value_from_map(core->map, i + 1, 1)));
// 			i += (2 + get_next_index(cmd - 1, get_value_from_map(core->map, i + 1, 1)));
// 		}
// 		else if (cmd != 0 && cmd <= 17 && !g_op_tab[cmd - 1].codage_octal)
// 		{
// 			printf("command : %s\t\tpc : %x\tindex : %d\tnext index = %d\n", g_op_tab[cmd - 1].command, core->map[i], i,
// 				get_next_index(get_value_from_map(core->map, i, 1) - 1, get_value_from_map(core->map, i + 1, 1)));
// 			i += (1 + g_sizes[cmd - 1][2]);
// 		}
// 		else
// 		{
// 			printf("command hasn't found\tpc : %x\tindex : %d\n", core->map[i], i);
// 			i++;
// 		}
// 	}
// }
