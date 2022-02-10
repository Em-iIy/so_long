/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:38:11 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/08 17:43:05 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2);
size_t	ft_strlen2(const char *s);
char	*ft_strchr2(const char *str, int c);
void	*ft_calloc2(unsigned int count, size_t size);

#endif