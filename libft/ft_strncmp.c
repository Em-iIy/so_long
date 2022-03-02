/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:44 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/02 12:12:13 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	int				ret;
	unsigned char	str1;
	unsigned char	str2;

	i = 0;
	str1 = s1[i];
	str2 = s2[i];
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && n--)
	{
		str1 = s1[i];
		str2 = s2[i];
		ret = str1 - str2;
		if (str1 != str2)
			return (ret);
		i++;
	}
	ret = str1 - str2;
	return (ret);
}
