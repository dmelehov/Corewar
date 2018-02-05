/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prog_attr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:26:39 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 17:26:41 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					print_prog_attr(char *data, unsigned int len)
{
	int					x;
	int					y;

	if (data)
	{
		x = (int)len % (FORMAT) == 0 ? -1 : -2;
		while (++x < (int)(len / FORMAT))
		{
			y = -1;
			while (++y < (int)FORMAT)
			{
				if (*data)
					printf("%s%.2x%s ", GREEN, *data++, RESET);
				else
					printf("%.2x ", *data++);
			}
			printf("\n");
		}
	}
}
