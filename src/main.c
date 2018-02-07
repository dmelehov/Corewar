/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:02:30 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/07 18:12:40 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	check_arguments(t_vm *vm)
{
	print_flags_struct(vm->flags);
	print_map_fragment(vm->map, 0, 8);
}

t_flags	*init_flags_struct(void)
{
	t_flags	*flags;

	flags = (t_flags *)ft_malloc_s(1, sizeof(t_flags));
	*flags = FLAGS_INIT;
	return (flags);
}

t_vm	*init_vm_struct(void)
{
	t_vm	*vm;

	vm = (t_vm *)ft_malloc_s(1, sizeof(t_vm));
	vm->map = (unsigned char *)ft_strnew(MEM_SIZE);
	vm->flags = init_flags_struct();
	return (vm);
}

int		main(int ac, char **av)
{
	t_vm	*vm;

	if (ac < 2)
		print_usage();
	vm = init_vm_struct();
	check_arguments(vm, ac, av);
	return (0);
}
