/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:40:08 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 22:40:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						validation(t_core *core, char *av)
{
	int			ret;

	ret = 1;
	if ((ret = read_file(core, av)) != 1)
	{
		ret == -1 ? printf("Can't read source file %s\n", av) : 0;
		ret == -2 ? printf("can't allocate a memory for %s\n", av) : 0;
		ret == -3 ? printf("can't read the file %s\n", av) : 0;
		return (0);
	}
	return (ret);
}
