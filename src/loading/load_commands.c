/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:28:05 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 19:28:07 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					load_commands(void)
{
	g_commands[0] = command_live;
	g_commands[1] = command_ld;
	g_commands[2] = command_st;
	g_commands[3] = command_add;
	g_commands[4] = command_sub;
	g_commands[5] = command_and;
	g_commands[6] = command_or;
	g_commands[7] = command_xor;
	g_commands[8] = command_zjmp;
	g_commands[9] = command_ldi;
	g_commands[10] = command_sti;
	g_commands[11] = command_fork;
	g_commands[12] = command_lld;
	g_commands[13] = command_lldi;
	g_commands[14] = command_lfork;
	g_commands[15] = command_aff;
}
