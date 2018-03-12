/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:02:21 by dshevche          #+#    #+#             */
/*   Updated: 2018/03/06 16:35:08 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int					ft_is_space(char c)
{
	if (c == '\t' || c == ' ' || c == SEPARATOR_CHAR
		|| c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static	int			ft_count_words(const char *str)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_is_space(str[i]) && ft_is_space(str[i + 1]) == 0)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static	char		*ft_word(const char *str, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(str)))))
		return (NULL);
	k = 0;
	while (ft_is_space(str[*i]) == 0 && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (ft_is_space(str[*i]) && str[*i])
		*i += 1;
	return (s);
}

char				*ft_clear_comment(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (flag == 1)
			str[i] = 0;
		if (str[i] == '#')
		{
			str[i] = 0;
			flag = 1;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}

char				**ft_split_cmd(char *str)
{
	int		i;
	int		j;
	int		wrd;
	char	**s;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	str = ft_clear_comment(str);
	wrd = ft_count_words(str);
	if (!(s = (char **)malloc(sizeof(char*) * (wrd + 2))))
		return (NULL);
	while (ft_is_space(str[i]) && str[i])
		i++;
	while (j < wrd && str[i])
	{
		s[j] = ft_word(str, &i);
		j++;
	}
	s[j] = NULL;
	return (s);
}
