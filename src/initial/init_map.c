/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:45:28 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 20:45:29 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

unsigned char			*init_map(void)
{
	unsigned char		*map;

	map = NULL;
	if (!(map = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE + 1)))
		return (NULL);
	else
		ft_bzero(map, MEM_SIZE);
	return (map);
}
