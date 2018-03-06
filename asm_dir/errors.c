/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:01:10 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 14:01:12 by dshevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	ft_err(char *err, int ret)
{
	if (ft_strequ("open", err))
		ft_putstr("error: open\n");
	else if (ft_strequ("empty", err))
		ft_putstr("error: file empty\n");
	else if (ft_strequ("malloc", err))
		ft_putstr("error: malloc\n");
	else if (ft_strequ("name", err))
		ft_putstr("error: invalid name\n");
	else if (ft_strequ("comment", err))
		ft_putstr("error: invalid comment\n");
	return (ret);
}
