/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:20:10 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/27 13:20:11 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					put_value_on_the_map(unsigned char *map, int start, int value)
{
	int				j;
	int				i;
	int				res;

	j = 4;
	while (j--)
	{
		i = 0;
		res = value;
		while (i++ < j)
			res = res >> 8;
		map[start] = (res & 0x000000ff);
		start++;
	}
}
