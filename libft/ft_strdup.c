/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:25 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/22 11:05:20 by gwinnink         ###   ########.fr       */
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
	ret_str[str_size] = (char) s1[str_size];
	while (str_size--)
		ret_str[str_size] = (char) s1[str_size];
	return (ret_str);
}
