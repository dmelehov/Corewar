/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_from_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:32:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 16:32:33 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

unsigned int			get_value_from_map(void *map, unsigned int start, unsigned int len)
{
	unsigned int	res;
	unsigned int	i;

	res = 0;
	i = 0;
	if (i < len)
	{
		while (i++ < len)
			res = (res << 8) | (((unsigned char *)map)[start++] & 0x000000ff);
	}
	return (res);
}
