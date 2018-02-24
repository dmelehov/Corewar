/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:15:45 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:33:22 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	op_st(t_vm *vm, t_proc *p)
{
	int adr;

	if (arg_checker(vm, p))
	{
		if (p->arg[1] == REG_CODE)
			p->reg[p->arg_v[1]]  = p->reg[p->arg_v[0]];
		else if (p->arg[1] == IND_CODE)
		{
			adr = p->pc + (p->arg_v[1] % IDX_MOD);
			update_map(vm, p, p->arg_v[0], adr);
		}
		ft_printf("P%5d | st r%d %d\n", p->num, p->arg_v[0],  p->arg_v[1]);
	}
}
