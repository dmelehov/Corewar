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

void	print_header_struct(t_header *h)
{
	ft_printf("{yellow}HEADER STRUCT: \n");
	ft_printf("--------------------\n");
	ft_printf("%-20s%x\n", "magic ==", h->magic);
	ft_printf("%-20s%s\n", "name ==", h->prog_name);
	ft_printf("%-20s%u\n", "size ==", h->prog_size);
//	ft_printf("%-20s%s\n", "comment ==", h->comment);
	ft_printf("--------------------\n{eoc}");
}

void	print_proc_struct(t_proc *proc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("{blue}PROC STRUCT: {eoc}\n");
	ft_printf("--------------------\n");
	ft_printf("{yellow}");
	ft_printf("%-20s{%d}\n{eoc}\n", "carret_position ==", proc->pc);
	ft_printf("{green}Registry :\n\t");
	while (i < 16)
	{
		ft_printf("[%x]", proc->reg[i++]);
		if (i % 4 == 0)
		{
			ft_printf("\n");
			j = i / 4 + 1;
			while (j--)
				ft_printf("\t");
		}
	}
	ft_printf("\n{eoc}");
	i = 0;
	ft_printf("{magenta}Arguments :\n\t");
	while (i < 3)
		ft_printf("[%x]", proc->arg[i++]);
	ft_printf("\n{eoc}\n");
	ft_printf("{yellow}");
	ft_printf("%-20s[%.2x]\n", "cur_cmd ==", proc->cur_cmd);
	ft_printf("%-20s%d\n", "wait ==", proc->wait);
	ft_printf("%-20s%d\n", "carry ==", proc->carry);
	ft_printf("%-20s%p\n", "next ==", proc->next);
	ft_printf("{eoc}");
	ft_printf("--------------------\n");
}

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
	ft_printf("{cyan}Map with start from {%d} :\n\t", start);
	while (i < end)
	{
		if (i != start)
			ft_printf(" ");
		ft_printf("{%.2x}", map[i]);
		i++;
	}
	ft_printf("{eoc}\n");
	ft_printf("--------------------\n\n");
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
