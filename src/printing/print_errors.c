/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 21:08:54 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 21:08:57 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						print_magic_error(char *dir)
{
	printf("Error: %s has an invalid header\n", dir);
	return (0);
}

int						print_prog_size_error(char *dir, int len)
{
	len < 0 ? printf("Error: File champs is too small to be a champion\n") : \
	printf("Error: File %s has too large a code (%d bytes > 682 bytes)\n", \
		dir, len);
	return (0);
}

int						print_usage(void)
{
	printf("Usage: ./corewar [ -d N -v N ] ");
	printf("[-n number] <champion1.cor> <...>\n");
	printf("    -n number\t: sets the number of the next player\n");
	printf("    --color\t: sets the color to output\n");
	printf("#### TEXT OUTPUT MODE ");
	printf("##########################################################\n");
	printf("    -d N\t: Dumps memory after N cycles then exits\n");
	printf("    -v N\t: Verbosity levels, can be added together ");
	printf("to enable several\n");
	printf("\t\t  - 0 : Show only essentials\n");
	printf("\t\t  - 1 : Show lives\n");
	printf("\t\t  - 2 : Show cycles\n");
	printf("\t\t  - 4 : Show operations (Params are NOT litteral ...)\n");
	printf("\t\t  - 8 : Show deaths\n");
	printf("\t\t  - 16 : Show PC movements (Except for jumps)\n");
	return (0);
}
