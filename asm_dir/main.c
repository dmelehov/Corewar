/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:31:43 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 13:31:48 by dshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				ft_check_end(char *name)
{
	char		*end;
	int			fd;
	int			i;

	i = -1;
	end = (char *)malloc(sizeof(char) * 1);
	if ((fd = open(name, O_RDONLY)) == -1)
		return (ft_err("open", 0));
	lseek(fd, -1, SEEK_END);
	read(fd, end, 1);
	while (*end == ' ' || *end == '\t')
	{
		lseek(fd, i, SEEK_END);
		read(fd, end, 1);
		i--;
	}
	close(fd);
	if (*end != '\n')
	{
		ft_print_n_err();
		free(end);
		return (-1);
	}
	free(end);
	return (0);
}

int				ft_free_list(t_line_list *list, t_main *main, int ret)
{
	t_line_list	*tmp;
	int			i;

	while (list)
	{
		i = 0;
		tmp = list->next;
		free(list->ent.r_line);
		while (list->ent.com[i])
			free(list->ent.com[i++]);
		free(list->ent.com[i]);
		free(list->ent.com);
		free(list);
		list = tmp;
	}
	ft_strdel(&main->name);
	ft_strdel(&main->comment);
	free(main->bytes);
	free(main->header);
	free(main);
	if (ret == -1)
		return (-1);
	else
		return (0);
}

t_main			*ft_init_main(void)
{
	t_main		*main;

	if ((main = (t_main*)malloc(sizeof(t_main))) == NULL)
		return (NULL);
	main->name = NULL;
	main->comment = NULL;
	main->bytes = NULL;
	main->header = NULL;
	return (main);
}

int				ft_assemble(char *name)
{
	t_line_list	*list;
	t_main		*main;

	if ((main = ft_init_main()) == NULL)
		return (ft_err("malloc", -1));
	if (ft_read_file(name, &list, main) == -1)
		return (ft_free_list(list, main, -1));
	if (ft_check_end(name))
		return (ft_free_list(list, main, -1));
	ft_get_position(list);
	if (ft_get_type_param(list) == -1)
		return (ft_free_list(list, main, -1));
	if (ft_remove_labels(list) == -1)
		return (ft_free_list(list, main, -1));
	ft_clear_list(&list);
	if (ft_is_valid(list) == -1)
		return (ft_free_list(list, main, -1));
	if (ft_bytecode(list, main) == -1)
		return (ft_free_list(list, main, -1));
	if (get_header(main, ft_get_max(list)) == -1)
		return (ft_free_list(list, main, -1));
	if (w_in_file(list, main, name) == -1)
		return (ft_free_list(list, main, -1));
	ft_free_list(list, main, 0);
	return (0);
}

int				main(int argc, char **argv)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		if ((ft_assemble(argv[i])) == -1)
			return (-1);
		i++;
	}
	if (i == 1)
	{
		ft_putstr("no input files\n");
		return (1);
	}
	return (0);
}
