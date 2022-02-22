/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:25 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/17 15:59:44 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc_wrap.h"

char	*ft_strdup(const char *s1)
{
	char	*ret_str;
	int		str_size;

	str_size = 0;
	while (s1[str_size])
		str_size++;
	ret_str = (char *)malloc_wrap(str_size + sizeof(char));
	if (ret_str == 0x0)
		return (ret_str);
	ret_str[str_size] = (char) s1[str_size];
	while (str_size--)
		ret_str[str_size] = (char) s1[str_size];
	return (ret_str);
}
