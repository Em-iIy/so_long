/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:27:47 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 11:27:48 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putptr(void *ptr)
{
	write(1, "0x", 2);
	return (ft_puthexnum((unsigned long)ptr, 0, 0) + 2);
}
