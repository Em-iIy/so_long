/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:20 by gwinnink          #+#    #+#             */
/*   Updated: 2021/12/14 13:44:21 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(const char *s, char c);
static char	**free_all(char **ret);

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		str_count;
	int		words;
	int		i;

	words = 0;
	str_count = ft_str_count(s, c);
	ret = (char **)malloc((str_count + 1) * sizeof(char *));
	if (ret == 0x0)
		return (0);
	while (words < str_count)
	{
		i = 0;
		while ((*s == c))
			s++;
		while (s[i] != c && s[i])
			i++;
		ret[words] = ft_substr(s, 0, i);
		if (!ret[words])
			return (free_all(ret));
		s += i;
		words++;
	}
	ret[str_count] = 0;
	return (ret);
}

static int	ft_str_count(const char *s, char c)
{
	int	str_count;
	int	i;

	str_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			str_count++;
		i++;
	}
	return (str_count);
}

static char	**free_all(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	return (0);
}
