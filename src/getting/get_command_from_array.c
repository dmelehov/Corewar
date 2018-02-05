/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_from_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:23:01 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:23:03 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						get_command_from_array(t_core *core, t_process *process, int key)
{
	load_commands();
	return ((key >= 0 && key <= 15) ? (*g_commands[key - 1])(core, process) : 0);
}
