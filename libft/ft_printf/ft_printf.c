/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:27:12 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 11:27:13 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_check_conv(char c, va_list args)
{
	if (!c)
		return (0);
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), '\0'));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int), 1));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, int), 0));
	else if (c == 'x')
		return (ft_puthexnum(va_arg(args, unsigned int), 0, 0));
	else if (c == 'X')
		return (ft_puthexnum(va_arg(args, unsigned int), 0, 1));
	else if (c == '%')
		return ((int)write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		char_count;
	va_list	args;

	va_start(args, str);
	i = 0;
	char_count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			char_count += ft_putstr((char *)str, '%');
			char_count += ft_check_conv(str[i + 1], args);
			str += i + 2;
			i = 0;
		}
		else
			i++;
	}
	char_count += ft_putstr((char *)str, '\0');
	va_end(args);
	return (char_count);
}
