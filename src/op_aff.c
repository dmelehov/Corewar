/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:23:50 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:28:17 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_aff(t_vm *vm, t_proc *p)
{
	if (arg_checker(vm, p) && vm->flags->a == 1)
		ft_printf("%d\n", (p->arg_v[0] % 256));
}
