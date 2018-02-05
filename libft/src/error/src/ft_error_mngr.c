/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_mngr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:33:00 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 20:57:17 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_debug_error_mngr(int er_code, char *error_msg)
{
	if (er_code == 1)
	{
		ft_printf("{red}");
		ft_putendl_fd(error_msg, 2);
		ft_printf("{eoc}");
		exit(-1);
	}
	else
		M_ERROR(-1, "ERROR");
}

void	ft_error_mngr(int num, char *error_msg)
{
	ft_putendl_fd(error_msg, 1);
	exit(num);
}
