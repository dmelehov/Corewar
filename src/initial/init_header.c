/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:46:53 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 20:46:54 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

t_header				*init_header(unsigned int magic, char *name, char *comment, char *prog)
{
	t_header			*header;

	if (!(header = (t_header *)malloc(sizeof(t_header))))
		return (NULL);
	header->magic = magic;
	header->prog_name = name;
	header->comment = comment;
	header->prog = prog;
	header->prog_size = 0;
	return (header);
}
