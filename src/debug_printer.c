/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:13:56 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/07 15:40:36 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_flags_struct(t_flags *fl)
{
	printf("FLAG STRUCT: \n");
	printf("--------------------\n");
	printf("%-20s%d\n", "flag a ==", fl->a);
	printf("%-20s%d\n", "flag d ==", fl->d);
	printf("%-20s%d\n", "flag s ==", fl->s);
	printf("%-20s%d\n", "flag v ==", fl->v);
	printf("%-20s%d\n", "flag b ==", fl->b);
	printf("%-20s%d\n", "flag n ==", fl->n);
	printf("--------------------\n");
}