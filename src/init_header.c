//
// Created by Dmitry Melehov on 2/12/18.
//

#include "../includes/vm.h"

/*
 * .COR STRUCTURE
 * 4	magic
 * PROG_NAME_LENGTH
 * '\0' + 3 bytes on NULL
 * 4	size of executable code
 * COMMENT_LENGTH
 * '\0' + 3 bytes on NULL
 * executable code
 */

int	get_magic(unsigned char *s)
{
	int magic;

	magic = s[0] << 24;
	magic += s[1] << 16;
	magic += s[2] << 8;
	magic += s[3];
	return (magic);
}

t_header 	*init_header_struct(unsigned char *data, int len)
{
	t_header	*hd;

	hd = (t_header *)ft_malloc_s(1, sizeof(t_header));
	hd->magic = get_magic(data);
	if (hd->magic != COREWAR_EXEC_MAGIC)
		M_ERROR(-1, "Nahuj takih chempionov bez magii");
	if (ft_strlen((char*)(data + 4)) >  PROG_NAME_LENGTH)
		M_ERROR(-1, "Too big champion name.");
	ft_bzero(hd->prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(hd->prog_name, data + 4, PROG_NAME_LENGTH);
	hd->prog_size = get_magic(data + PROG_NAME_LENGTH + 8);
	if (ft_strlen((char*)(data + PROG_NAME_LENGTH + 12)) > COMMENT_LENGTH)
		M_ERROR(-1, "Too big comment.");
	ft_bzero(hd->comment, PROG_NAME_LENGTH + 12);
	ft_memcpy(hd->comment, data + PROG_NAME_LENGTH + 12,  COMMENT_LENGTH);
	if (len - HEADER != hd->prog_size)
		M_ERROR(-1, "Prog size doesn't match real.");
//	print_header_struct(hd);
	return (hd);
}