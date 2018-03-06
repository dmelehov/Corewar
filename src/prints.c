/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:09:02 by fmallaba          #+#    #+#             */
/*   Updated: 2018/03/02 17:34:36 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		print_winner(t_vm *vm)
{
	if (vm->flags->n)
		end_game(vm);
	else if (vm->winner)
		ft_printf("Contestant %d, \"%s\", has won !\n",
			(PL_NUM - vm->winner->num + 1),
			vm->winner->header->prog_name);
}

void		print_map(unsigned char *map)
{
	int		i;

	i = -1;
	ft_printf("0x0000 : ");
	while (++i < 4096)
	{
		if (i && !(i % 64))
			ft_printf("\n%#06x : ", i);
		ft_printf("%02x ", map[i]);
	}
	ft_printf("\n");
}

void		print_intro(t_vm *vm)
{
	int			i;
	t_players	*p[4];

	get_plr_arr(p, vm->pls);
	ft_printf("Introducing contestants...\n");
	i = -1;
	while (++i < vm->pl_q)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
			i + 1, p[vm->pl_q - 1 - i]->header->prog_size,
			p[vm->pl_q - 1 - i]->header->prog_name,
			p[vm->pl_q - 1 - i]->header->comment);
	}
}
