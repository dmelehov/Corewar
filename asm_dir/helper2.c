/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:58:58 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 16:43:11 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		ft_print_n_err(void)
{
	ft_printf("Syntax error - unexpected end of input ");
	ft_printf("(Perhaps you forgot to end with a newline ?)\n");
}

int			ft_is_label(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = -1;
	while (str[++i])
		;
	if (str[i - 1] == ':')
		return (1);
	else
		return (0);
}

int			ft_atoi_ret(int neg)
{
	if (neg)
		return (0);
	else
		return (2147483647);
}

int			ft_atoi_1(const char *str)
{
	int			i;
	uintmax_t	nbr;
	int			negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\t') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		if (nbr > MY_LONG_MAX)
			return (ft_atoi_ret(negative));
		i++;
	}
	if (negative == 1)
		return (int)(-nbr);
	else
		return (int)(nbr);
}

int			ft_check_label_char(t_line_list *list, int n)
{
	int i;
	int pos;

	i = -1;
	if (list->ent.com[n][0] == '%')
		i = 0;
	while (list->ent.com[n][++i])
	{
		if (ft_strchr(LABEL_CHARS, list->ent.com[n][++i]) == 0)
		{
			pos = ft_get_pos(list->ent.r_line, list->ent.com[n]);
			ft_printf("Lexical error at [");
			ft_printf("%d:", list->ent.nbr);
			ft_printf("%d]\n", pos + i + 1);
			return (-1);
		}
	}
	return (0);
}
