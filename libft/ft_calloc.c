/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:43:36 by gwinnink          #+#    #+#             */
/*   Updated: 2021/12/14 13:43:37 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int count, size_t size)
{
	char			*ret_ptr;
	unsigned int	i;

	ret_ptr = (void *)malloc(count * size);
	if (ret_ptr == 0x0)
		return ((void *)ret_ptr);
	i = 0;
	while (i < count * size)
	{
		ret_ptr[i] = 0;
		i++;
	}
	return ((void *)ret_ptr);
}
