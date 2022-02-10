/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:27:38 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 11:27:39 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	ft_hexconv(unsigned long n, int upper)
{
	if (n < 10)
		return (n + '0');
	else if (upper == 1)
		return ((n % 10) + 'A');
	return ((n % 10) + 'a');
}

int	ft_puthexnum(unsigned long n, int len, int upper)
{
	unsigned long	out;
	unsigned long	temp;

	temp = n;
	out = ft_hexconv(temp % 16, upper);
	temp /= 16;
	len++;
	if (temp > 0)
		len = ft_puthexnum((unsigned long)temp, len, upper);
	write(1, &out, 1);
	return (len);
}
