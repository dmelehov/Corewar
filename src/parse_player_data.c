/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:28:46 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/08 16:57:17 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

#define FILE_MAX_LEN (PROG_NAME_LENGTH + COMMENT_LENGTH + 16)

static void	read_champ_data(t_vm *vm, char *str, int count)
{
	int	fd;
	int len;

	if ((fd = open(str, O_RDONLY)) < 3)
		M_ERROR(-1, ft_strjoin("Can't read source file ", str));
	len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);



}

void	get_champions_data(t_vm *vm, char *str, int count)
{
	char	*s;
	char	*name;

	if (count >= 4)
		M_ERROR(-1, "Too many champions");
	if (!(s = ft_strrchr(str, '/')))
		name = ft_strsub(str, 0, ft_strrchr(str, '.') - str);
	else
		name = ft_strsub(s + 1, 0, (ft_strrchr(str, '.') - s - 1));
	(vm->players)[count].name = name;
	printf("The champion name is {%s}\n", (vm->players)[count].name);
	read_champ_data(vm, str, count);
}
