/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:28:00 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 11:28:01 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr(int n, int signd);
int		ft_putstr(char *s, char end);
int		ft_putchar(char c);
int		ft_puthexnum(unsigned long n, int len, int upper);
int		ft_putptr(void *ptr);

#endif