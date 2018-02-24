/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:02:30 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/23 18:42:02 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"



int		main(int ac, char **av)
{
	t_vm	*vm;

	if (ac < 2)
		print_usage();
	av++;
	ac--;
	vm = init_vm_struct(ac, av);
	check_arguments(vm, ac, av);

	game_cycle(vm);
	print_winner(vm->winner);
	return (0);
}
