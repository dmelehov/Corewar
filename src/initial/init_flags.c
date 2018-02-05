/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:48:20 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 20:48:22 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

t_flags					*init_flags(void)
{
	t_flags				*flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	flags->dump = 0;
	flags->dump_cycle = 0;
	flags->number = 0;
	flags->v = 0;
	flags->verbosity = 0;
	flags->verbosity_one = 0;
	flags->verbosity_two = 0;
	flags->verbosity_four = 0;
	flags->verbosity_eight = 0;
	flags->verbosity_sixteen = 0;
	flags->color = 0;
	flags->n = 0;
	return (flags);
}
