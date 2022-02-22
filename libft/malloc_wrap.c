/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_wrap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:48:17 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/22 10:54:04 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/so_long.h"
#include <stdlib.h>

void	*malloc_wrap(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		error_and_exit(MALLOC_ERROR);
	return (ret);
}
