/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:27:44 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 11:27:45 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

static int	ft_putnbr_fd(int n, int fd, int len)
{
	int		out;
	long	tmp;

	tmp = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		tmp *= -1;
		len++;
	}
	out = tmp % 10 + '0';
	tmp /= 10;
	len++;
	if (tmp > 0)
		len = ft_putnbr_fd((int)tmp, fd, len);
	write(fd, &out, 1);
	return (len);
}

static int	ft_putunbr_fd(unsigned int n, int fd, int len)
{
	int				out;
	unsigned int	tmp;

	tmp = n;
	out = tmp % 10 + '0';
	tmp /= 10;
	len++;
	if (tmp > 0)
		len = ft_putnbr_fd((int)tmp, fd, len);
	write(fd, &out, 1);
	return (len);
}

int	ft_putnbr(int n, int signd)
{
	int	len;

	len = 0;
	if (signd == 1)
	{
		if (n == INT_MIN)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		len = ft_putnbr_fd(n, 1, 0);
	}
	else
		len = ft_putunbr_fd(n, 1, 0);
	return (len);
}
