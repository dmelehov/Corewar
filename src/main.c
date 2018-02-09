/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:02:30 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/08 16:30:33 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

bool	check_champion(char *str)
{
	char	*s;

	if (!(s = ft_strrchr(str, '.')))
		return (false);
	if (!ft_strequ(s, ".cor"))
		return (false);
	if (ft_strlen(str) == 4)
		return (false);
	return (true);
}

void	check_arguments(t_vm *vm, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	parse_flags(vm, ac, av);
	print_flags_struct(vm->flags);
	print_map_fragment(vm->map, 0, 8);
	printf("ac == %d\n", ac);
	while (i < ac)
	{
		if (check_champion(av[i]))
		{
			get_champions_data(vm, av[i], j);
			j++;
		}
		printf("%s\n", av[i++]);
	}
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
	av++;
	ac--;
	check_arguments(vm, ac, av);
	return (0);
}
