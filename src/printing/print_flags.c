/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:16:43 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 17:16:44 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					print_flags(t_flags *flags)
{
	printf("flag one: %d\n", flags->verbosity_one);
	printf("flag two: %d\n", flags->verbosity_two);
	printf("flag four: %d\n", flags->verbosity_four);
	printf("flag eight: %d\n", flags->verbosity_eight);
	printf("flag sixteen: %d\n", flags->verbosity_sixteen);
}
