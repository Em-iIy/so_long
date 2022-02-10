/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:54 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/08 16:30:57 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ret_str;
	unsigned int	i;

	i = 0;
	ret_str = (char *)malloc((len + 1) * sizeof(char));
	if (ret_str == 0x0)
		return (ret_str);
	while (i < len && s[start + i] && start < ft_strlen(s))
	{
		ret_str[i] = s[start + i];
		i++;
	}
	ret_str[i] = 0;
	return (ret_str);
}
