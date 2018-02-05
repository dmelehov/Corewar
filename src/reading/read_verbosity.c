/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_verbosity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:13:30 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/06 21:13:32 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					read_verbosity(t_core *core)
{
	FLAGS->verbosity_sixteen = ft_to_bin(FLAGS->verbosity & 16) / 10000;
	FLAGS->verbosity_eight = ft_to_bin(FLAGS->verbosity & 8) / 1000;
	FLAGS->verbosity_four = ft_to_bin(FLAGS->verbosity & 4) / 100;
	FLAGS->verbosity_two = ft_to_bin(FLAGS->verbosity & 2) / 10;
	FLAGS->verbosity_one = ft_to_bin(FLAGS->verbosity & 1);
}
