/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:11:54 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/23 16:11:55 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						read_file(t_core *core, char *av)
{
	int					fd;
	unsigned int		len;
	unsigned char		*data;
	t_header			*header;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (-1);
	len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!(data = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (-2);
	if (!(read(fd, data, len)))
		return (-3);
	if (len - ((PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16) > CHAMP_MAX_SIZE)
		return (print_prog_size_error(av, len - ((PROG_NAME_LENGTH) + \
			(COMMENT_LENGTH) + 16)));
	if (!(header = parse_header(data, len)))
		return (print_magic_error(av));
	add_player(core->players, header, len, core->flags);
	free(data);
	close(fd);
	return (1);
}
