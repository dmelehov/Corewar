/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:27:03 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/07 17:36:18 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	void	*s;

	s = (char *)ft_malloc_s(size + 1, sizeof(char));
	size += 1;
	while (size--)
		*(unsigned char *)(s + size) = '\0';
	return (s);
}
