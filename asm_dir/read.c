/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:59:22 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/12 12:57:41 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int					check_cmd_lable(char *s, char *cmd, int pos, int *nbr)
{
	pos += skip_wspcs(s);
	if (!ft_strcmp(cmd, s + pos))
		exit(ft_printf("Syntax error on raw %d, symbol %d\n",
							(*nbr), ft_strlen(cmd) + pos));
	pos += ft_strlen(cmd);
	pos += skip_wspcs(s + pos);
	if (s[pos] != 34 && s[pos] != '\0')
		exit(ft_printf("Syntax error on raw %d, symbol %d\n",
					(*nbr), pos));
	else if (s[pos] == '\0')
		exit(ft_printf("Break line %d, symbol %d\n",
				(*nbr) + 1, 0));
	return (pos + 1);
}

static char			*get_the_fucking_ptr(char *s, int i, int *nbr, char **res)
{
	char			*ptr;
	int				r;

	ptr = ft_strchr(s + i, 34);
	if (ptr == NULL)
		(*res) = ft_strjoin(s + i, "\n");
	else
	{
		if ((r = check_eos(ptr + 1)) != 0)
			exit(ft_printf("Syntax error on raw %d, symbol %d\n",
					(*nbr), i + r));
		(*res) = ft_strsub(s + i, 0, ptr - (s + i));
		ft_strdel(&s);
		return (ptr);
	}
	return (ptr);
}

char				*set_name(char *s, int fd, int *nbr, char *cmd)
{
	int				r;
	char			*ptr;
	char			*res;

	if ((ptr = get_the_fucking_ptr(s,
					check_cmd_lable(s, cmd, 0, nbr), nbr, &res)))
		return (res);
	while (ptr == NULL)
	{
		ft_strdel(&s);
		if ((r = get_next_line(fd, &s)) < 0)
			M_ERROR(-1, "Reading error\n");
		else if (r == 0)
			exit(ft_printf("There is no %s at all\n", cmd + 1));
		(*nbr)++;
		ptr = some_modifying(&res, s);
	}
	if ((r = check_eos(ptr + 1)) != 0)
		exit(ft_printf("Syntax error on raw %d, symbol %d\n",
					(*nbr), r));
	some_modifying_two(s, ptr, &res);
	return (res);
}

void				ft_read_n_c(char *s, t_main *main, int fd, int *nbr)
{
	if (ft_strstr(s, ".name") && main->name == NULL)
		main->name = set_name(s, fd, nbr, ".name");
	else if (ft_strstr(s, ".name"))
		M_ERROR(-1, "a name already exist");
	else if (ft_strstr(s, ".comment") && main->comment == NULL)
		main->comment = set_name(s, fd, nbr, ".comment");
	else if (ft_strstr(s, ".comment"))
		M_ERROR(-1, "a comment already exist");
	else
		M_ERROR(-1, "Not a valid sequence");
}

int					ft_read_file(char *name, t_line_list **list,
									t_main *main, int r)
{
	int			fd;
	char		*str;
	int			nbr;

	*list = NULL;
	nbr = 0;
	if ((fd = open(name, O_RDONLY)) < 3)
		return (ft_err("open", -1));
	while ((r = get_next_line(fd, &str)) > 0)
	{
		nbr++;
		if (ft_is_empty(str) == 0)
		{
			if (main->name == NULL || main->comment == NULL)
				ft_read_n_c(str, main, fd, &nbr);
			else if (read_helper(list, &str, &nbr) == -1)
				return (-1);
		}
	}
	r == -1 ? M_ERROR(-1, "Not a file") : close(fd);
	free(str);
	if (*list == NULL)
		return (ft_err("empty", -1));
	return (ft_check_len(main));
}
