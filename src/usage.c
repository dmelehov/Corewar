/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:18:35 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/07 18:06:17 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

#define STR "##########################################################"

void	print_usage(void)
{
	ft_putstr("Usage: ./corewar [-d N -s N -v N | -b --stealth | ");
	ft_putendl("-n --stealth] [-a] <champion1.cor> <...>");
	ft_putendl("\t-a\t\t: Prints output from \"aff\" (Default is to hide it)");
	ft_putstr("#### TEXT OUTPUT MODE ###");
	ft_putendl(STR);
	ft_putendl("\t-d N\t\t: Dumps memory after N cycles then exits");
	ft_putendl("\t-s N\t\t: Runs N cycles, dumps memory, pauses, then repeats");
	ft_putstr("\t-v N\t\t: Verbosity levels, ");
	ft_putendl("can be added together to enable several");
	ft_putendl("\t\t\t\t- 0 : Show only essentials");
	ft_putendl("\t\t\t\t- 1 : Show lives");
	ft_putendl("\t\t\t\t- 2 : Show cycles");
	ft_putendl("\t\t\t\t- 4 : Show operations (Params are NOT litteral ...)");
	ft_putendl("\t\t\t\t- 8 : Show deaths");
	ft_putendl("\t\t\t\t- 16 : Show PC movements (Except for jumps)");
	ft_putstr("#### NCURSES OUTPUT MODE ");
	ft_putendl(STR);
	ft_putendl("\t-n\t\t: Ncurses output mode");
	ft_putendl("\t--stealth : Hides the real contents of the memory");
	ft_putendl("\t--sound : Sound effect");
	ft_putstr("#########################");
	M_ERROR(0, STR);
}

#undef STR
