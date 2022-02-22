/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:41 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/17 15:59:17 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc_wrap.h"

char	*ft_strmapi(const char	*s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	i = 0;
	if (!s)
		return (0);
	ret = (char *)malloc_wrap(ft_strlen(s) + 1);
	if (ret == 0x0)
		return (ret);
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
