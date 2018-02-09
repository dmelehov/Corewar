/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:13:56 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/07 19:40:43 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_flags_struct(t_flags *fl)
{
	ft_printf("FLAG STRUCT: \n");
	ft_printf("--------------------\n");
	ft_printf("%-20s%d\n", "flag a ==", fl->a);
	ft_printf("%-20s%d\n", "flag d ==", fl->d);
	ft_printf("%-20s%d\n", "flag s ==", fl->s);
	ft_printf("%-20s%d\n", "flag v ==", fl->v);
	ft_printf("%-20s%d\n", "flag b ==", fl->b);
	ft_printf("%-20s%d\n", "flag n ==", fl->n);
	ft_printf("--------------------\n");
}

void	print_map_fragment(unsigned char *map, int start, int end)
{
	int	i;

	i = start;
	ft_printf("Map with start from {%d} :\n\t", start);
	while (i < end)
	{
		if (i != start)
			ft_printf(" ");
		ft_printf("%.2x", map[i]);
		i++;
	}
	printf("\n");
}

void	print_map(unsigned char *map)
{
	int		i;

	i = -1;
	ft_printf("0x0000 :");
	while (++i < 4096)
	{
		if (i && !(i % 64))
			ft_printf("\n%#06x :", i);
		ft_printf(" %02x", map[i]);
	}
	ft_printf("\n");
}
