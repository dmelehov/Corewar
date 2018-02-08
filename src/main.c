/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:02:30 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/08 14:20:27 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	get_champions_data(t_vm *vm, char *str, int count)
{
	char	*s;
	char	*name;

	if (count >= 4)
		M_ERROR(-1, "Too many champions");
	if (!(s = ft_strrchr(str, '/')))
		name = ft_strsub(str, 0, ft_strrchr(str, '.') - str);
	else
		name = ft_strsub(s + 1, 0, (ft_strrchr(str, '.') - s - 1));
	(vm->players)[count].name = name;
	printf("{%s}\n", (vm->players)[count].name);
}

bool	check_champion(char *str)
{
	char	*s;

	if (!(s = ft_strrchr(str, '.')))
		return (false);
	if (!ft_strequ(s, ".cor"))
		return (false);
	return (true);
}

int		check_players_quantity(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		if (check_champion(av[i]))
			j++;
		i++;
	}
	if (j > 4)
		M_ERROR(-1, "Too many champions");
	else if (j == 0)
		print_usage();
	return (j);
}

void	check_arguments(t_vm *vm, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//
	print_flags_struct(vm->flags);
	print_map_fragment(vm->map, 0, 8);
	printf("ac == %d\n", ac);
	while (i < ac)
	{
		printf("av[%d] == %s\n", i, av[i]);
		if (check_champion(av[i]))
		{
			printf("We've got a champion with name: \n");
			get_champions_data(vm, av[i], j);
			j++;
		}
		i++;
	}
}

t_flags	*init_flags_struct(void)
{
	t_flags	*flags;

	flags = (t_flags *)ft_malloc_s(1, sizeof(t_flags));
	*flags = FLAGS_INIT;
	return (flags);
}

t_vm	*init_vm_struct(int ac, char **av)
{
	t_vm	*vm;

	vm = (t_vm *)ft_malloc_s(1, sizeof(t_vm));
	vm->pl_q = check_players_quantity(ac, av);
	vm->map = (unsigned char *)ft_strnew(MEM_SIZE);
	vm->flags = init_flags_struct();
	return (vm);
}

int		main(int ac, char **av)
{
	t_vm	*vm;

	if (ac < 2)
		print_usage();
	av++;
	ac--;
	vm = init_vm_struct(ac, av);
	check_arguments(vm, ac, av);
	return (0);
}
