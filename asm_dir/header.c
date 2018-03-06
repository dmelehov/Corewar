/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:58:40 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 17:12:48 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		little_to_big_endian(int nb)
{
	nb = ((nb << 8) & 0xFF00FF00) | ((nb >> 8) & 0xFF00FF);
	return (nb << 16) | ((nb >> 16) & 0xFFFF);
}

void	ft_put_name_comment(t_main *main)
{
	int	i;

	i = 0;
	while (main->name[i++])
		main->header->prog_name[i - 1] = main->name[i - 1];
	while (i < PROG_NAME_LENGTH + 1)
		main->header->prog_name[i++] = 0;
	i = 0;
	while (main->comment[i++])
		main->header->comment[i - 1] = main->comment[i - 1];
	while (i < COMMENT_LENGTH + 1)
		main->header->comment[i++] = 0;
}

int		get_header(t_main *main, int size)
{
	unsigned char	*head_tmp;
	int				head_size;
	int				i;

	if ((main->header = (t_header*)malloc(sizeof(*main->header))) == NULL)
		return (ft_err("malloc", -1));
	i = 0;
	head_size = sizeof(main->header);
	head_tmp = (unsigned char*)main->header;
	while (i < head_size)
		head_tmp[i++] = 0;
	main->header->magic =
	(unsigned int)little_to_big_endian(COREWAR_EXEC_MAGIC);
	main->header->prog_size = (unsigned int)little_to_big_endian(size);
	ft_put_name_comment(main);
	return (0);
}
