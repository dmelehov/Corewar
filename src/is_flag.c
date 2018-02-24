/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:35:44 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/24 20:34:14 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

bool	is_flag(char *av)
{
	char *flags;

	flags = "adsvbn";
	if (*av != '-' || ft_strlen(av) != 2)
		return (false);
	av++;
	while (*flags)
		if (*av == *flags++)
			return (true);
	return (false);
}

int 	flag_attr(char *av)
{
	if (av[1] == 'd' || av[1] == 's' || av[1] == 'v')
		return (1);
	return (0);
}
