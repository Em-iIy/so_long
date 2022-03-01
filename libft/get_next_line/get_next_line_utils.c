/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:37:24 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/01 11:28:23 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc_wrap.h"
#include <stddef.h>

size_t	ft_strlen2(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

void	*ft_calloc2(unsigned int count, size_t size)
{
	char			*ret_ptr;
	unsigned int	i;

	i = 0;
	ret_ptr = (char *)malloc_wrap(count * size);
	if (!ret_ptr)
		return (NULL);
	while (i < count * size)
	{
		ret_ptr[i] = 0;
		i++;
	}
	return ((void *)ret_ptr);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = (char *)ft_calloc2(1, 1);
	ret_str = (char *)ft_calloc2(ft_strlen2(s1) + ft_strlen2(s2) + 1, 1);
	if (!ret_str)
		return (NULL);
	while (s1[i])
	{
		ret_str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		ret_str[i + j] = s2[j];
		j++;
	}
	return (ret_str);
}

char	*ft_strchr2(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}
