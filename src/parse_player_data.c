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

static int	get_magic(unsigned char *s)
{
	int magic;

	magic = s[0] << 24;
	magic += s[1] << 16;
	magic += s[2] << 8;
	magic += s[3];

	printf("The fucking magic num is : {%#x}\n", magic);
	return (magic);
}

static void	check_champ_size(char *path, int len)
{
	if (len <  0)
	{
		ft_printf("Error: File champs is too small to be a champion");
		M_ERROR(-1, "");
	}
	else if (len - FILE_MAX_LEN > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s has too large a code (%d bytes > 682 bytes)", path, len);
		M_ERROR(-1, "");
	}
}

static t_header *init_header_struct(unsigned char *data, int len)
{
	t_header	*hd;

	hd = (t_header *)ft_malloc_s(1, sizeof(t_header));
	hd->magic = COREWAR_EXEC_MAGIC;
	ft_bzero(hd->prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(hd->prog_name, data + 4, PROG_NAME_LENGTH);
	ft_bzero(hd->comment, PROG_NAME_LENGTH + 12);
	ft_memcpy(hd->comment, data + PROG_NAME_LENGTH + 12,  COMMENT_LENGTH);
	printf("Prog name == %s\n", hd->prog_name);
	printf("Comment == %s\n", hd->comment);
	return (hd);
}

static void	read_champ_data(t_vm *vm, char *str, int count)
{
	int	fd;
	int len;
	unsigned char	*s;

	if ((fd = open(str, O_RDONLY)) < 3)
		M_ERROR(-1, ft_strjoin("Can't read source file ", str));
	len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	check_champ_size(str, len);
	s = (unsigned char *)ft_strnew(len);
	if (read(fd, s, len) <= 0)
		M_ERROR(-1, ft_strjoin("Can't read source file ", str));
	if (get_magic(s) != COREWAR_EXEC_MAGIC)
		M_ERROR(-1, "Nahuj takih chempionov bez magii");
	vm->players[count].header = init_header_struct(s, len);
	printf("START POSITION == {%d}\n", (MEM_SIZE/vm->pl_q * count));
	ft_memcpy(vm->map + (MEM_SIZE/vm->pl_q * count), s + FILE_MAX_LEN, len - FILE_MAX_LEN);

//	ft_printf("Error: %s has an invalid header\n", str);



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
