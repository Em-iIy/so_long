/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:43:36 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/22 11:07:21 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc_wrap.h"

void	*ft_calloc(unsigned int count, size_t size)
{
	char			*ret_ptr;
	unsigned int	i;

	ret_ptr = (void *)malloc_wrap(count * size);
	i = 0;
	while (i < count * size)
	{
		ret_ptr[i] = 0;
		i++;
	}
	return ((void *)ret_ptr);
}
